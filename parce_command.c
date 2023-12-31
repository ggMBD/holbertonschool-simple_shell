#include "shell.h"

/**
 * parse_cmd - Parses the command recieved from stdin
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */
char **parse_cmd(char *input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		perror("hsh");
		return (NULL);
	}
	argument = strtok(input, DELIMITER);
	for (i = 0; argument; i++)
	{
		arguments[i] = strdup(argument);
		argument = strtok(NULL, DELIMITER);
	}
	arguments[i] = NULL;
	return (arguments);
}
