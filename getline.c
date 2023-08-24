#include "shell.h"
/**
 * read_line - fuction that read line from stdin
 * Return: line readed
*/

char *read_line(void)
{
	char *line = NULL;
	int byte_read;
	size_t len = 0;

	byte_read = getline(&line, &len, stdin);
	if (feof(stdin))
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	if (byte_read == -1)
	{
		perror("error readline");
		exit(EXIT_FAILURE);
	}

	if (strcmp(line, "exit\n") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
