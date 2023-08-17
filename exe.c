#include "main.h"
/**
 * executeCommand - execute the command
 * @command: the command
 * @f_n: file name : argv[0]
 * @envp: environ
 * @cc: commands counter
 * Return: void
*/

void executeCommand(char *command, char *f_n, char **envp, int cc)
{
	pid_t pid;
	char *args[2];

	args[0] = strdup(command);

	if (args[0] == NULL)
	{
		perror("strdup fail");
		exit(EXIT_FAILURE);
	}
	args[1] = NULL;
	pid = fork();

	if (pid == -1)
	{
		perror("fork fail");
		free(args[0]);
	}
	else if (pid == 0)
	{
		execve(args[0], args, envp);
		dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", f_n, cc, args[0]);
		free(args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		free(args[0]);
	}
}
