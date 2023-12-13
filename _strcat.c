/**
 * *_strcat - String concatenator.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Reversed string \n.
 */

char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int z = 0;

	while (dest[dest_len])
		dest_len++;

	while (src[z])
	{
		dest[dest_len] = src[z];
		dest_len++;
		z++;
	}
	dest[dest_len] = '\0';
	return (dest);
}
