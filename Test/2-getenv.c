#include "main.h"
/**
 * _getenv : compares the keyword input with environment variables
 * @name: keyword
 * Return: NULL if fails, the value associated with the key if success
*/

extern char **environ;

char * _getenv(const char *name) 
{
	char ** env_var = environ;
	size_t name_length;
	char * value;

	if (name == NULL || environ == NULL) 
	{
		return (NULL);
	}

	name_length = strlen(name);

	while (*env_var != NULL)
	{
		if (strncmp(*env_var, name, name_length) == 0 && (*env_var)[name_length] == '=')
		{
			/**value takes env_var from the index of value name_length + 1 ('=')**/
			value = *env_var + name_length + 1;
			return (value);
		}
		env_var++;
	}
	return (NULL);
}

/**
 * main - calls _getenv function with PATH keyword
 * Return: -1 if fails, 0 if success
 */
int main() 
{
	/**here getenv is called with "PATH" it could be any other key from environment variables**/
	char * path = _getenv("PATH");

	if (!path)
	{
		printf("PATH not found\n");
		return (-1);
	}

	printf("PATH=%s\n", path);

	return (0);
}
