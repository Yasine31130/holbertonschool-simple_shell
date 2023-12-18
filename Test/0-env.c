#include "main.h"

extern char ** environ;
/**
 * main - prints the environement with the environ variable
 * Return: 0 success
 */
int main()
{
	char ** env_var = environ;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
	return (0);
}
