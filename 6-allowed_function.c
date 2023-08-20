#include "shell.h"
/**
 * allowed - check the function
 * @command: function to check it
 * Return: function is allowed (1) else (0)
 */
int allowed(char *command)
{
	int i;
	char ac[][16] = {"ls", "pwd", "cd", "env", "mv", "rm", ""};

	for (i = 0; ac[i][0] != '\0'; i++)
	{
		if (!strncmp(ac[i], command, strlen(ac[i])))
			return (1);
	}
	return (0);
}
