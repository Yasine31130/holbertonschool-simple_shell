#include "main.h"
/**
 * _getenv - custom getenv function, get the environments variables
 * @name: command argument to compare with the key
 * Return: the value of the environment variable
 */
char *_getenv(const char *name)
{
	int i;
	char *token;

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
