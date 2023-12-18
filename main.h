#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_CMD_LEN 1024
#define MAX_ARGS 32
extern char **environ;
void execute_cmd(char **args);
void _printenv();
void get_args(char *cmd);
char *_getenv(const char *name);
#endif
