#include "shell.h"
/**
 * signal_to_handle - Configures ^C not to terminate our shell
 * @sig: Incoming Signal
 */
void signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		PRINT("\n$ ");
	}
}