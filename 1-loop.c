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

	clear();
	while (1)
	{
		if (isatty(0))
			printf("$ ");

		input = read_line();
		if (allowed(input))
		{
			command = tok(input);
			executeCommand(command, argv[0], envp, cc);
			free_double_pointer(command);
			cc++;
		}
		else
		{
			free(input);
		}
	}
	return (0);
}
