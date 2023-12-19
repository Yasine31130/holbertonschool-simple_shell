#include "main.h"
/**
 * search_in_path - handle the path when user input doesn't contain it
 * @args: command line arguments
 * @path: the path
 */
void search_in_path(char **args, char *path)
{
    char *token = strtok(path, ":");
    char full_path[MAX_CMD_LEN];
    int len;

    while (token != NULL)
    {
        len = strlen(token) + strlen("/") + strlen(args[0]) + 1;
        if (len > MAX_CMD_LEN)
        {
            fprintf(stderr, "Path is too long\n");
            exit(EXIT_FAILURE);
        }
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, args[0]);

        /**Check if the command exists in the current directory**/
        if (strcmp(args[0], "ls") == 0 && access(args[0], F_OK) == 0)
        {
            // Execute the command in the current directory
            if (execve(args[0], args, environ) == -1)
            {
                perror(args[0]);
                exit(EXIT_FAILURE);
            }
        }

        /**Check if the command exists in the directory specified in the PATH**/
        if (access(full_path, F_OK) == 0)
        {
            /**Execute the command with the specified path**/
            if (execve(full_path, args, environ) == -1)
            {
                perror(args[0]);
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, ":");
    }
    /**Display an error message if the command was not found**/
    fprintf(stderr, "%s: command not found\n", args[0]);
    exit(EXIT_FAILURE);
}

int compare_strings(const void *a, const void *b)
{
	return strcmp(*(const char **)a, *(const char **)b);
}
