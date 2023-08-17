#include "shell.h"
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
	size_t len;
	int read, i, cc = 1;

	while (1)
	{
		if(isatty(0))
			printf("$ ");
		read = getline(&input, &len, stdin);
		if (!strcmp(input, "exit\n"))
		{
			exit(EXIT_SUCCESS);
			free(input);
		}
		if (read == -1)
		{
			free(input);
			if (feof(stdin))
			{
			exit(EXIT_SUCCESS);
			free(input);
			}
			else
			{
			perror("error readline");
			exit(EXIT_FAILURE);
			break;
			}
		}
		command = tok(input);
		executeCommand(command, argv[0], envp, cc);
		cc++;
	}
	for (i = 0; command[i] != NULL; i++)
	{
		free(command[i]);
	}
	free(command);
	free(input);
	return (0);
}
