#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;
#define MAX 100
char *read_line(void);
char **tok(char *str);
void executeCommand(char **command, char *f_n, char **envp, int cc);
/**
 * main - simple shell
 * @argc: argument counter
 * @argv: list of argument
 * @envp: environ list
 * Return: success 0
*/

int main(int argc __attribute__((__unused__)), char **argv, char **envp)
{
	char *input = NULL, **command;
	int i, cc = 1;

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		input = read_line();
		command = tok(input);
		executeCommand(command, argv[0], envp, cc);
		cc++;
	}
	for (i = 0; command[i] != NULL; i++)
		free(command[i]);
	free(command);
	free(input);
	return (0);
}
#include "shell.h"

char* read_line(void)
{
	char *input = NULL;
	int read;
	size_t len = 0;

	read = getline(&input, &len, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
		exit(EXIT_SUCCESS);
		}
		else
		{
		perror("error readline");
		exit(EXIT_FAILURE);
		}
	}
	if (strcmp(input, "exit\n") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	return (input);
}
#include "shell.h"

#define BUFSIZE 64
#define DELIM " \n "
/**
 * tok - function that remove spaces form str
 * @str: string
 * Return: (tokens)
*/
char **tok(char *str)
{
	int bufsize = BUFSIZE, position = 0, i;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("lsh: allocation error");
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(str, DELIM);
	while (token != NULL)
	{
		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("sh: reallocation error");
				for (i = 0; tokens[i] != NULL; i++)
				{
					free(tokens[i]);
				}
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
		tokens[position] = strdup(token);
		if (!tokens[position])
		{
		perror("sh: duplicate error");
		exit(EXIT_FAILURE);
		}
		position++;
		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	free(token);
	return (tokens);
}

#include "shell.h"
/**
 * executeCommand - execute the command
 * @command: the command
 * @f_n: file name : argv[0]
 * @envp: environ
 * @cc: commands counter
 * Return: void
*/

void executeCommand(char **command, char *f_n, char **envp, int cc)
{
	pid_t pid;
	char *path;

	pid = fork();

	if (pid == -1)
	{
		perror("fork fail");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command[0], command, envp);
		path = strtok(getenv("PATH"), ":");
		while (path)
		{
			char executable_path[MAX];

			strcpy(executable_path, path);
			strcat(executable_path, "/");
			strcat(executable_path, command[0]);
			execve(executable_path, command, envp);
			path = strtok(NULL, ":");
		}
		dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", f_n, cc, command[0]);
		free(path);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
