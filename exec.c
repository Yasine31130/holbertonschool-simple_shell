#include "main.h"
/**
 *
 */
void execute_cmd(char **args)
{
	pid_t pid;
	char * path;
	char * token;
	char full_path[MAX_CMD_LEN];

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror(args[0]);
				exit(EXIT_FAILURE);
			}
		}
		/**If no path is provided, search for the executable in PATH**/
		path = getenv("PATH");
		token = strtok(path, ":");

		while (token != NULL)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", token, args[0]);

			/**Execute the command if found in the current path**/
			if (execve(full_path, args, environ) != -1)
			{
				/**If execution is successful, break out of the loop**/
				exit(EXIT_SUCCESS);
			}

			token = strtok(NULL, ":");
		}

		/**If the loop completes, the command was not found in any path**/
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	/**Parent process**/
	wait(NULL);
}
