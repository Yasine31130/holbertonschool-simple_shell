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
	char ** array = NULL;
	size_t arraySize = 0;

	/**Tokenize the string**/
	token = strtok(str, delimiter);

	while (token != NULL)
	{
		arraySize++;
		/**Dynamically reallocate memory to the array each time we are adding a token**/
		array = realloc(array, (arraySize) * sizeof(char *));
		array[arraySize - 1] = token;

		/**Move to the next token**/
		token = strtok(NULL, delimiter);
	}

	return(array);
}
