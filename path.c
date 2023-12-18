#include "main.h"
/**
 * search_in_path - handle the path when user input doesn't contain it
 * @args: command line arguments
 * @path: the path
*/
void search_in_path(char **args, char *path)
{
	char *token = strtok(path, ":");
	char full_path[MAX_CMD_LEN];
	int len;

	while (token != NULL)
	{
		len = strlen(token) + strlen("/") + strlen(args[0]) + 1;
		if (len > MAX_CMD_LEN)
		{
			fprintf(stderr, "Path is too long\n");
			exit(EXIT_FAILURE);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, args[0]);

		if (execve(full_path, args, environ) != -1)
		{
			exit(EXIT_SUCCESS);
		}
		token = strtok(NULL, ":");
	}
	perror(args[0]);
	exit(EXIT_FAILURE);
}
