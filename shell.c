#include "shell.h"
/**
* main - entry point to the pogram
*@argc: arguments count
*@argv: arguments vector.
*
*Return : Returns condition.
*/
int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int count = 0, condition = 1, stat = 0;

	while (condition)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = read_line();
		if (input[0] == '\n')
		{
			free(input);
			continue;
		}

		if (strncmp(input, "env\n", 4) == 0)
		{
			_env();
			free(input);
			continue;
		}
		cmd = parse_cmd(input);
		if (cmd != NULL)
		{
			stat = check_cmd(cmd, count, argv);
			free_double_pointer(cmd);
		}
		free(input);
	}
	return (stat);
}
