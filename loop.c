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
	int cc = 1;

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		input = read_line();
		command = tok(input);
		executeCommand(command, argv[0], envp, cc);
		free_tokens(command);
		free(input);
		cc++;
	}
	return (0);
}
