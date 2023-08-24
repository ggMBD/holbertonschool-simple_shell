#include "shell.h"

/**
 * print_error - Displays error message
 * @input: Input recieved from user
 * @counter: Count of shell loop
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINT(argv[0]);
	PRINT(": ");
	er = _itoa(counter);
	PRINT(er);
	free(er);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}
