#include "main.h"

/**
 * handle_sig - the signal handle
 * @sig: the signal
 *
 * Return: void
 */

void handle_sig(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 4);
	fflush(stdout);
}
