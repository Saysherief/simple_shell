/**
 * *_strcpy - copies the string pointed by src
 * @src: a pointer to the string /the first char on the string
 * @dest: a pointer to copy at a destination
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0;

	while (src[len] != '\0')
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of a string
 *
 * @s: a pointer to the string the first charon the string
 * Return: an integer which is the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcat - concatenates the second string to the first and retuns the address
 * @dest: address of the second string
 * @src: address of the first string
 * Return: address of the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	for (; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
