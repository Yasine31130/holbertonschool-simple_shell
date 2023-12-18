#include "main.h"
/**
 *
 */
char *_getenv(const char *name)
{
	int i;
	char * token;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(environ[i], "=");

		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "\0");
			return token;
		}
	}

	return (NULL);
}
