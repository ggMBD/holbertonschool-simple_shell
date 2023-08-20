#include "shell.h"
/**
 * executeCommand - execute the command
 * @command: the command
 * @file_name: file name : argv[0]
 * @envp: environ
 * @cc: commands counter
 * Return: void
*/

void executeCommand(char **command, char *file_name, char **envp, int cc)
{
	pid_t pid;
	char *path;

	pid = fork();

	if (pid == -1)
	{
		perror("fork fail");
		free(command);
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
		dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", file_name, cc, command[0]);
		free(path);
		free_double_pointer(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
