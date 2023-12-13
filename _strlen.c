/**
 * _strlen - Get the lenght of string.
 * @s: The string pointer.
 * Return: The lenght of string.
 */
int _strlen(char *s)
{
	int len = 0;
	int z = 0;

	while (*(s + z) != '\0')
	{
		len++;
		z++;
	}
	return (len);
}
