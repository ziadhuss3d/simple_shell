/**
 * *_strcmp - The code ASCII dif.
 * @s1: The first string.
 * @s2: The second string.
 * Return: The integer of the dif ASCII value.
 */

int _strcmp(char *s1, char *s2)
{
	int z = 0;

	while (s1[z] == s2[z])
	{
		if (s1[z] == '\0')
		{
			return (0);
		}
		z++;
	}
	return (s1[z] - s2[z]);
}
