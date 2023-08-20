#ifndef SHELL
#define SHELL
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define clear() printf("\033[H\033[J")
extern char **environ;
#define MAX 100
int allowed(char *command);
char *read_line(void);
char **tok(char *str);
void executeCommand(char **command, char *f_n, char **envp, int cc);
void free_double_pointer(char **tokens);


#endif
