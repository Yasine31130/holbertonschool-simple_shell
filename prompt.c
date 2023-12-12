#include "main.h"
/**
 *
 */
int main(void)
{
	char * line = 0;
	size_t buffer_size = 0;
	ssize_t bytes_read;

	while (1)
	{
		printf("$");
		bytes_read = getline(&line, &buffer_size, stdin);

		if (bytes_read != -1)
			printf("%s", line);
	}

	free (line);
	return (0);
}
