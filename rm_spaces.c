#include "main.h"
/**
 * rm_spaces - function that remove spaces form str
 * @str: string
*/
void rm_spaces(char *str)
{
	int counter = 0, i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			str[counter] = str[i];
			counter++;
		}
	}
	str[counter] = '\0';
}
