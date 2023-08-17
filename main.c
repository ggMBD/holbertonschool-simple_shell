#include "main.h"
/**
 * main - simple shell
 * @argc: argument counter
 * @argv: list of argument
 * @envp: environ list
 * Return: success 0
*/

int main(int argc __attribute__((__unused__)), char **argv, char **envp)
{
	char *input = NULL;
	size_t len;
	int read, cc = 1;

	while (1)
	{
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

		if (input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}
		rm_spaces(input);
		executeCommand(input, argv[0], envp, cc);
		cc++;
	}

	free(input);
	return (0);
}
