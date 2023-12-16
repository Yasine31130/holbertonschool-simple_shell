#include "main.h"

extern char ** environ;
/**
 * _getenv - Get the value of an environment variablr
 * @name: variable to check
 * Return: The value of the variable or NULL if it doesn't
 */
char * _getenv(const char * name)
{
	int i;
	char * token;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "\0");
			return (token);
		}
	}
	return (NULL);
}

/**
 * main - calls getenv()
 * @argc: number of arguments
 * @argv: Arguments value
 * Return: 0 SUCCESS
 */
int main(int argc, char ** argv)
{
	char ** env_val;

	if (argc != 2)
	{
		printf("error\n");
		return (-1);
	}

	*env_val = _getenv(argv[1]);
	printf("%s\n", *env_val);
	return (0);
}
