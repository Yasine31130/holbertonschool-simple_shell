#include "main.h"
/**
 *
 */
int main ()
{
	char * argv[] = {"/bin/ls", "-l", NULL};
	int val;
	pid_t pid;
	
	pid = fork ();

	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		val = execve(argv[0], argv, NULL);

		if (val == -1)
			perror("Error");
	}

	wait(NULL);
	printf("After execve\n");

	return (0);
}
