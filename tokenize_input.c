#include "main.h"

/**
 * tokenize_input - Tokenize the input.
 * @userInput_buf: User input to be tokenized.
 *
 * Return: The string tokenized.
 */

char **tokenize_input(char *userInput_buf)
{
	char **args = NULL;
	char *separate = " \n\t";
	char *pars;
	int indx = 0;

	pars = strtok(userInput_buf, separate);

	while (pars != NULL)
	{
		args = realloc(args, (indx + 2) * sizeof(char *));
		args[indx] = malloc(strlen(pars) + 1);
		strcpy(args[indx++], pars);
		pars = strtok(NULL, separate);
	}

	args[indx] = NULL;
	free(pars);
	return (args);
}
