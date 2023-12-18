#include "main.h"
/**
 * execute_command - handle failure for the cmd executed
 * @args: command arguments
 */
void execute_command(char **args)
{
	if (execve(args[0], args, environ) == -1)
	{
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
}
