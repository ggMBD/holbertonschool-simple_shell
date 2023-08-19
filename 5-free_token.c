#include "shell.h"
/**
 * free_tokens - function free free tokens
 * @tokens: tokens to free
*/
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
