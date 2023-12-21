#include "main.h"
/**
 * _getenv - custom getenv function, tokenize environments variables
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
			/**2nd token here corresponding to the value of PATH**/
			token = strtok(NULL, "\0");
			return (token);
		}
	}

	return (NULL);
}
