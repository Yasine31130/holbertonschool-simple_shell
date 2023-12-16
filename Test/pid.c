#include "main.h"
/**
 * main - prints the pid
 * Return: 0
 */
int main(void)
{
        pid_t pid;

        pid = getpid();
        printf("%d\n", pid);

        return (0);
}
