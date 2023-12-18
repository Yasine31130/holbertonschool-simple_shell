#include "main.h"
/**
 *
 */
void execute_command(char **args)
{
    if (execve(args[0], args, environ) == -1)
    {
        perror(args[0]);
        exit(EXIT_FAILURE);
    }
}
