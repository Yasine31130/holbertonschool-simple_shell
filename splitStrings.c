#include "main.h"
/**
 * splitString - splits the string into tokens
 * @str: the string
 * @delimiter: delimits the token inside the string
 * Return: array of tokens
 */
char ** splitString(char * str, const char * delimiter)
{
	char * token;
	char ** array;
	int i = 1;

	array = malloc(sizeof(array));
	
	token = strtok(str, delimiter);
	array[0] = token;

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok (NULL, delimiter);
		if (token != NULL)
		{
			array[i] = token;
			i = i + 1;
		}
	}

	return(array);
}
