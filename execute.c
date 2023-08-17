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
		free(command[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command[0], command, NULL);
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
		free(command[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		free(command[0]);
	}
}
