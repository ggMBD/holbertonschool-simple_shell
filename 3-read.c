#include "shell.h"
/**
 * read_line - fuction that read line from stdin
 * Return: line readed
*/
char *read_line(void)
{
	char *line = NULL;
	int read;
	size_t len = 0;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("error readline");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	if (strcmp(line, "exit\n") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
