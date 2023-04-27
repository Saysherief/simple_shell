#include "shell.h"

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

/**
 * _itoa - converts int to a string
 * @num: number to convert
 *
 * Return: nothing
 */
char *_itoa(int num)
{
	char *str = malloc(sizeof(char) * (32 + 1));
	int i = 0, neg = 0;

	if (num < 0)
	{
		neg = 1;
		num = -num;
	}
	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);
	if (neg)
		str[i++] = '-';

	str[i] = '\0';
	rev_string(str);

	return (str);
}

/**
 * rev_string - reverses a string
 * @s: the string
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i, len;
	char tmp;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	len--;
	for (i = 0; i < len; i++)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		len--;
	}
}
