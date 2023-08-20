#include "shell.h"
/**
 * free_double_pointer - function free pointer
 * @pointer: pointer to free
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
