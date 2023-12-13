#include "main.h"

/**
 * free_args - A function free the memory for command args
 * @args: the command args
 *
 * Return: void
 */

void free_args(char **args)
{
	int z;

	for (z = 0; args[z] != NULL; z++)
	{
		free(args[z]);
	}
	free(args[z]);
}
