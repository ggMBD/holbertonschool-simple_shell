#include "shell.h"

#define BUFSIZE 64
#define DELIM " \n "
/**
 * tok - function that remove spaces form str
 * @str: string
 * Return: (tokens)
*/
char **tok(char *str)
{
	int bufsize = BUFSIZE, position = 0, i;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("lsh: allocation error");
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(str, DELIM);
	if(!token)
	{
		free(token);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("sh: reallocation error");
				for (i = 0; tokens[i] != NULL; i++)
				{
					free(tokens[i]);
				}
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
		tokens[position] = strdup(token);
		if (!tokens[position])
		{
		perror("sh: duplicate error");
		exit(EXIT_FAILURE);
		}
		position++;
		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	free(token);
	return (tokens);
}
