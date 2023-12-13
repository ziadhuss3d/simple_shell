#include "main.h"

/**
 * _sprintf - The sprintf Function that concatenates three strings.
 * @str: Concatenate string
 * @delim: The delimiteur
 * @src: Source of string
 * Return: New string pointer
 */

char *_sprintf(char *str, char *delim, char *src)
{
	char *new_str;
	int len_str, len_delim, len_src;

	len_str = strlen(str);
	len_delim = strlen(delim);
	len_src = strlen(src);

	new_str = malloc((len_str + len_delim + len_src + 1) * sizeof(char));
	if (new_str == NULL)
	{
		perror("ERROR: FAILD MALLOC");
		exit(EXIT_FAILURE);
	}

	strcpy(new_str, str);
	strcat(new_str, delim);
	strcat(new_str, src);

	return (new_str);
}
