#include "main.h"
/**
 * main - main function, gets the command user line input
 * Return: 0 success but never executes the return as loop's infinite
 */
int main(void)
{
	char *cmd = NULL;
	size_t cmd_len = 0;
	ssize_t bytes_read;

	while (1)
	{
		/**we check that we are in interactive mode**/
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		bytes_read = getline(&cmd, &cmd_len, stdin);

		if (bytes_read == -1)
		{
			printf("\n");
			free(cmd);
			exit(EXIT_SUCCESS);
		}

		/**Remove extra linebreak when user press enter**/
		if (cmd[bytes_read - 1] == '\n')
			cmd[bytes_read - 1] = '\0';

		get_args(cmd);

		/**Free the memory allocated by getline**/
		free(cmd);
		cmd = NULL;
		cmd_len = 0;
	}
	return (0);
}
