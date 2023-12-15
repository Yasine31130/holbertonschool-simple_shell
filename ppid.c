#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
 * print_ppid - prints the ppid
 * Return: 0
 */
int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%d\n", ppid);

	return (0);
}
