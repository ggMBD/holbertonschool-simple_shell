#include "shell.h"
/**
 * signal_handler - Configures ^C not to terminate our shell
 * @signum: Incoming Signal
 */
void signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		PRINT("\n$ ");
	}
}
