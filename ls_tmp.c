#include "main.h"
/**
 * main - executes the command ls -l /tmp in 5 different child process
 * Return: 0 success
 */
int main ()
{
	int pid;
	int i = 0;
	int value;
	char * argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (i < 5)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(98);
		}
		if (pid == 0)
		{
			printf("Child process %d before execve\n", getpid());
			value = execve(argv[0], argv, NULL);

			if (value == -1)
			{
				perror("execve");
				exit(98);
			}
		}
		wait(NULL);
		printf("Parent process after the child process %d has exited\n", pid);
		i++;
	}
	return (0);
}
