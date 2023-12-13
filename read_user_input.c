#include "main.h"

/**
 * read_user_input - a function Reads the input from user.
 * @userInput_buf: hold input from user
 * @buff_size: the buffer size
 *
 * Return: number of chars read when success, -1 if failure.
 */

ssize_t read_user_input(char **userInput_buf, size_t *buff_size)
{
	ssize_t readNUM;

	readNUM = getline(userInput_buf, buff_size, stdin);
	if (readNUM == -1)
	{
		if (!isatty(STDIN_FILENO))
			return (-1);
		free(userInput_buf);
		perror("getline()");
		exit(EXIT_FAILURE);
	}
	if ((*userInput_buf)[readNUM - 1] == '\n')
		(*userInput_buf)[readNUM - 1] = '\0';

	return (readNUM);
}
