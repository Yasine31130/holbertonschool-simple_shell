#include "main.h"
/**
 * main - prints "$", wait for the user to enter a cmd and prints it on the next line
 * Return: 0 if success
 */
int main()
{
	char * line = NULL;
	size_t buffer_size = 0;
	ssize_t bytes_read;
	const char * delimiter = " ";
	char ** array;

	while (1)
	{
		printf("$");
		bytes_read = getline(&line, &buffer_size, stdin);
                // We don't do anything if bytes_read = 1 because it means that getline returned only the line break
		if (bytes_read != 1)
		{
			printf("%s", line);
			array = splitString(line, delimiter);
			free (array);
		}
	}
	free (line);
	return (0);
}
