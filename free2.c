#include "shell.h"
/**
 * free_double_pointer - free double pointer
 * @pointer: pointer to free it
*/
void free_double_pointer(char **pointer)
{
	int i;

	for (i = 0; pointer[i] != NULL; i++)
	{
		free(pointer[i]);
	}
	free(pointer);
}

