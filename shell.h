#ifndef SHELL
#define SHELL
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;
#define MAX 100

char **tok(char *str);
void executeCommand(char **command, char *f_n, char **envp, int cc);



#endif