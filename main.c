#include "main.h"
/**
 * main - The shell function.
 *
 * Return: 0 if success
 */

int main(void)
{
	char *userInput_buf, **args = NULL;
	int exit_nm = -1;
	size_t buff_size = 0, z;

	while (666)
	{
		userInput_buf = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (read_user_input(userInput_buf, &buff_size) == -1)
		{
			free(userInput_buf);
			break;
		}
		if (userInput_buf[0] == '\0')
		{
			free(userInput_buf);
			continue;
		}
		if (check_spaces_tabs(userInput_buf))
		{
			free(userInput_buf);
		}
		args = tokenize_input(userInput_buf);
		if (!validate_command(args, userInput_buf, exit_nm))
		{
			free(userInput_buf);
			continue;
		}
		exit_nm = execute_forked_command(args, userInput_buf);
		if (args != NULL)
		{
			for (z = 0; args[z] != NULL; z++)
				free(args[z]);
			free(args);
		}
		free(userInput_buf);
	}
	return (0);
}
