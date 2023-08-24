#include "shell.h"

/**
 * check_cmd - Excutes commands found in predefined path
 * @cmd: Array of parsed command strings
 * @c:Shell Excution Time Case of Command Not Found
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_cmd(char **cmd, int c, char **argv)
{
	pid_t pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (strncmp(*cmd, "./", 2) != 0 && strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			print_error(cmd[0], c, argv);
			free(cmd);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(NULL);


	return (127);
}
