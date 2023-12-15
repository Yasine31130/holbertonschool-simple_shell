#include "main.h"
/**
 *
 */
int main ()
{
	char * argv[] = {"/bin/ls", "-l", NULL};
	int val;
	
	val = execve(argv[0], argv, NULL);

	if (val == -1)
		perror("Error");

	printf("Done");

	return (0);
}
