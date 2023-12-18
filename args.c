#include "main.h"
/**
 *
 */
void _printenv(void)
{
	char ** env_var = environ;
	while (*env_var != NULL) {
		printf("%s\n", *env_var);
		env_var++;
	}
}

/**
 *
 */
void get_args(char *cmd)
{
	char * args[MAX_ARGS];
	size_t arg_count = 0;
	char * token;
	unsigned int i;

	token = strtok(cmd, " ");

	for (i = 0; token != NULL; ++i)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		arg_count++;
	}
	/**adds NULL pointer at the end of the array**/
	args[arg_count] = NULL;

	if (arg_count > 0)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}

		else if (strcmp(args[0], "env") == 0) {
			_printenv();
		}
		/**Execute external command**/
		execute_cmd(args);
	}
}
