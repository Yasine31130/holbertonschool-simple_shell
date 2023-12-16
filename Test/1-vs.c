#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Success 0
 */
extern char ** environ;

int main(int ac, char **av, char **env)
{
	char ** env_val = environ;
	unsigned int i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	printf("\n\n");
	while (*env_val)
	{
		printf("%s\n", *env_val);
		env_val++;
	}
	return (0);
}
