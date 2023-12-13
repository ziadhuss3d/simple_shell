#include "main.h"

/**
 * handle_builtins - The builtin handles function.
 * @args: The args.
 * @userInput_buf: The user buffer inputs.
 * @exit_nm: Status to exit.
 *
 * Return: Exit 1 or 0 for the env.
 */

int handle_builtins(char **args, char *userInput_buf, int exit_nm)
{
	char **env;
	int exit_stat = EXIT_SUCCESS;
	int z;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			exit_stat = atoi(args[1]);
		else if (exit_nm != -1)
			exit_stat = exit_nm;
		for (z = 0; args[z] != NULL; z++)
		{
			free(args[z]);
			args[z] = NULL;
		}
		free(args);
		free(userInput_buf);
		exit(exit_stat);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (env = environ; *env; ++env)
			printf("%s\n", *env);
		free_args(args);
		return (1);
	}
	return (0);
}
