#include "main.h"
/**
 * execute_cmd - executes the command arguments
 * @args: command arguments
 */
void execute_cmd(char **args)
{
	pid_t pid;
	char *path;
	int i;
	int has_path;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		has_path = 0;
		for (i = 0; args[0][i] != '\0'; ++i)
		{
			if (args[0][i] == '/')
			{
				has_path = 1;
				break;
			}
		}
		if (has_path)
		{
			execute_command(args);
			exit(EXIT_SUCCESS);
		}
		path = _getenv("PATH");
		search_in_path(args, path);
	}
	wait(NULL);
}
