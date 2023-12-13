#include "main.h"

/**
 * validate_command - check the command if its an exists or builtin.
 * @args: the args command
 * @exit_no: exit with number.
 * @userInput_buf: the buffer inputs.
 *
 * Return: 1 if is valid, 0 if not.
 */

int validate_command(char **args, char *userInput_buf, int exit_no)
{
	if (handle_builtins(args, userInput_buf, exit_no))
	{
		return (0);
	}
	if (!command_exists(args))
	{
		fprintf(stderr, "COMMAND NOT FOUND: %s\n", args[0]);
		free_args(args);
		return (0);
	}

	return (1);
}
