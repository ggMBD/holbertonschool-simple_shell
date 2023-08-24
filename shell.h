#ifndef SHELL
#define SHELL
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>


#define PRINT(c) (write(STDERR_FILENO, c, strlen(c)))
#define BUFSIZE 1024
#define DELIMITER " \t\n"
#define clear() printf("\033[H\033[J")
#define MAX 100

extern char **environ;

void signal_handler(int signum);
void prompt(void);
char *read_line(void);
char **parse_cmd(char *input);
int check_cmd(char **cmd, int c, char **argv);
int path_cmd(char **cmd);
char *build(char *token, char *value);
char *_getenv(char *name);
char *_itoa(unsigned int n);
void array_rev(char *arr, int len);
int intlen(int num);
void print_error(char *input, int counter, char **argv);
void free_double_pointer(char **pointer);
void _env(void);

#endif
