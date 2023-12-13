/**
 * _strcpy - Copy str code.
 * @dest: The string destination.
 * @src: The sourc string.
 * Return: The pointer to the destination string.
 *
 */

char *_strcpy(char *dest, char *src)
{
	int z = 0;

	while (*(src + z))
	{
		*(dest + z) = *(src + z);
		z++;
	}
	*(dest + z) = '\0';
	return (dest);
}
