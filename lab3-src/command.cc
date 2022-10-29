
/*
 * CS354: Shell project
 *
 * Template file.
 * You will need to add more code here to execute the command table.
 *
 * NOTE: You are responsible for fixing any bugs this code may have!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

#include "command.h"

SimpleCommand::SimpleCommand()
{
	// Creat available space for 5 arguments
	_numberOfAvailableArguments = 5;
	_numberOfArguments = 0;
	_arguments = (char **) malloc( _numberOfAvailableArguments * sizeof( char * ) );
}

void
SimpleCommand::insertArgument( char * argument )
{
	if ( _numberOfAvailableArguments == _numberOfArguments  + 1 ) {
		// Double the available space
		_numberOfAvailableArguments *= 2;
		_arguments = (char **) realloc( _arguments,
				  _numberOfAvailableArguments * sizeof( char * ) );
	}
	
	_arguments[ _numberOfArguments ] = argument;

	// Add NULL argument at the end
	_arguments[ _numberOfArguments + 1] = NULL;
	
	_numberOfArguments++;
}

Command::Command()
{
	// Create available space for one simple command
	_numberOfAvailableSimpleCommands = 1;
	_simpleCommands = (SimpleCommand **)
		malloc( _numberOfSimpleCommands * sizeof( SimpleCommand * ) );

	_numberOfSimpleCommands = 0;
	_outFile = 0;
	_inputFile = 0;
	_errFile = 0;
	_background = 0;
	_appendFlag = 0;
}

void
Command::insertSimpleCommand( SimpleCommand * simpleCommand )
{
	if ( _numberOfAvailableSimpleCommands == _numberOfSimpleCommands ) {
		_numberOfAvailableSimpleCommands *= 2;
		_simpleCommands = (SimpleCommand **) realloc( _simpleCommands,
			 _numberOfAvailableSimpleCommands * sizeof( SimpleCommand * ) );
	}
	
	_simpleCommands[ _numberOfSimpleCommands ] = simpleCommand;
	_numberOfSimpleCommands++;
}

void
Command:: clear()
{
	for ( int i = 0; i < _numberOfSimpleCommands; i++ ) {
		for ( int j = 0; j < _simpleCommands[ i ]->_numberOfArguments; j ++ ) {
			free ( _simpleCommands[ i ]->_arguments[ j ] );
		}
		
		free ( _simpleCommands[ i ]->_arguments );
		free ( _simpleCommands[ i ] );
	}

	if ( _outFile ) {
		free( _outFile );
	}

	if ( _inputFile ) {
		free( _inputFile );
	}

	if ( _errFile ) {
		free( _errFile );
	}

	_numberOfSimpleCommands = 0;
	_outFile = 0;
	_inputFile = 0;
	_errFile = 0;
	_background = 0;
}

void
Command::print()
{
	printf("\n\n");
	printf("              COMMAND TABLE                \n");
	printf("\n");
	printf("  #   Simple Commands\n");
	printf("  --- ----------------------------------------------------------\n");
	
	for ( int i = 0; i < _numberOfSimpleCommands; i++ ) {
		printf("  %-3d ", i );
		for ( int j = 0; j < _simpleCommands[i]->_numberOfArguments; j++ ) {
			printf("\"%s\" \t", _simpleCommands[i]->_arguments[ j ] );
		}
		printf("\n");
	}

	printf( "\n\n" );
	printf( "  Output       Input        Error        Background\n" );
	printf( "  ------------ ------------ ------------ ------------\n" );
	printf( "  %-12s %-12s %-12s %-12s\n", _outFile?_outFile:"default",
		_inputFile?_inputFile:"default", _errFile?_errFile:"default",
		_background?"YES":"NO");
	printf( "\n\n" );
	
}

void
Command::execute()
{
	// Don't do anything if there are no simple commands
	if ( _numberOfSimpleCommands == 0 ) {
		prompt();
		return;
	}
	print();
	// stem call creates a copy of a file descriptor.
	// here, we take stdin(0) and put it in default in and so on.
	int defaultin = dup( 0 );
	int defaultout = dup( 1 );
	int defaulterr = dup( 2 );
	int outfd = 0;
	int infd = 0;
	printf("Here is defaultin %d\n",defaultin);
	printf("Here is defaultout %d\n",defaultout);
	printf("Here is defaulterr %d\n",defaulterr);

	// setting the right file descriptors to redirect to

	if (_outFile && _appendFlag){
		// create file descriptor for outfd to append to
		outfd = open(_outFile, O_CREAT | O_APPEND | O_WRONLY);
		// O_CREAT: if file doesn't exist create it
		// O_APPEND: if file exists append to it
		// O_WRONLY: write only
		// printf("appended to a file\n");	
		}
	else if(_outFile){
		// create file descriptor for outfd to overwrite to
		outfd = open(_outFile, O_CREAT | O_WRONLY | O_TRUNC);
		// O_CREAT: if file doesn't exist create it
		// O_TRUNC: if file exists delete what's in it
		// O_WRONLY: write only
		//printf("created a file\n");
	}
	else{
		// if _outFile = 0, file descriptor remains the same
		outfd = defaultout;
	}
	if (_inputFile){
		// create file descriptor for infd
		infd = open(_inputFile, O_RDONLY);
		// O_RDONLY: read only
	}
	else{
		// if _inputFile = 0, file descriptor remains the same
		infd = defaultin;
	}

	// Start redirecting the right file descriptors to stdin, stdout
	dup2(infd,0);
	dup2(outfd,1);
	dup2(defaulterr,2);

	int pid;
	int n = sizeof(_simpleCommands)/sizeof(SimpleCommand*);
	// Looping on simple commands, each: cmd + [args]* 
	for (int i = 0; i < n; i++){
		// If at the end
		if(i == n - 1){
			pid = fork();
			if (pid==0){
				int num_args = _simpleCommands[i]->_numberOfArguments;
				char ** args = _simpleCommands[i]->_arguments;
				char ** full_command = (char **) realloc(args,(num_args + 1) * sizeof(char*));
				full_command[num_args] = NULL;
				execvp(full_command[0],full_command);
				_exit(1);
			}
		}
		else{ // Else if we are still in the middle of commands
		// Create child process
			pid = fork();
			if (pid == -1){
				perror("There is an error. Process can't be created\n");
				exit(2);
			}
			if (pid == 0){
				
				close(outfd);
				close(infd);
				close(defaultin);
				close(defaultout);
				close(defaulterr);
				exit(0);
			}

		}	




	

	}

	// dup2 takes first argument and puts it in second argument (opposite of dup)
	// here, we return input to be stdin, output to be stdout, and error to be stderr

	dup2(defaultin,0);
	dup2(defaultout,1);
	dup2(defaulterr,2);

	// Close file descriptors that are not needed
	close(defaultin);
	close(defaultout);
	close(defaulterr);
	close(outfd);
	close(infd);



	// Clear to prepare for next command
	clear();
	
	// Print new prompt
	prompt();
}

// Shell implementation

void
Command::prompt()
{
	printf("myshell>");
	fflush(stdout);
}

Command Command::_currentCommand;
SimpleCommand * Command::_currentSimpleCommand;

int yyparse(void);

int 
main()
{
	Command::_currentCommand.prompt();
	yyparse();
	return 0;
}

