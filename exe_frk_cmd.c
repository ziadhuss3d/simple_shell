#include "main.h"

/**
 * execute_forked_command - fork the process and execute the command.
 * @userInput_buf: buffer of th inputs.
 * @args: the args commands.
 *
 * Return: void.
 */

int execute_forked_command(char **args, char *userInput_buf)
{
	pid_t pid;
	int stat;
	int z;

	pid = fork();
	if (pid == -1)
	{
		perror("FORK");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execute_command(args, userInput_buf) == -1)
		{
			perror(userInput_buf);
			for (z = 0; args[z] != NULL; z++)
			{
				free(args[z]);
			}
			free(args);
			free(userInput_buf);
			exit(EXIT_FAILURE);
		}
	}
	if (wait(&stat) == -1)
		perror("WAIT");
	if (WIFEXITED(stat))
		return (WEXITSTATUS(stat));
	return (-1);
}
