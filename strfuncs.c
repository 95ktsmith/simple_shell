#include "holberton.h"

/**
 * _strdup - string duplicate
 * Description: Duplicates a string
 * @str: Source string
 * Return: Pointer to newly created string
 */

char *_strdup(char *str)
{
	int index, size;
	char *dst;

	if (str == NULL)
		return (NULL);

	size = 0;
	while (*(str + size))
		size++;

	dst = malloc(size + 1);
	if (dst == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		*(dst + index) = *(str + index);

	*(dst + index) = '\0';

	return (dst);
}

/**
 * _strchr - String Character
 * Description: Returns a pointer to the first occurance of character c in
 *              string s.
 * @c: Character being looked for.
 * @s: String
 * Return: Pointer to character in string, or NULL if not found
 */

char *_strchr(char *s, char c)
{
	char *p = s;

	while (*p != c && *p != '\0')
		p++;

	if (c != '\0')
	{
		if (*p == '\0')
			return (0);
		else
			return (p);
	}
	else
		return (p);
}

/**
 * _strstr - Search for string
 * Description: Searches for a string within another string.
 * @haystack: String to search through
 * @needle: String to search for
 * Return: Pointer to start of the needle string if found, null otherwise.
 */

char *_strstr(char *haystack, char *needle)
{
	int hindex, nindex;

	for (hindex = 0; *(haystack + hindex) != '\0'; hindex++)
	{
		for (nindex = 0; *(needle + nindex) != '\0'; nindex++)
		{
			if (*(haystack + hindex + nindex) != '\0')
			{
				if (*(haystack + hindex + nindex) !=
				    *(needle + nindex))
					break;
			}
			else
				break;
		}
		if (*(needle + nindex) == '\0')
			return (haystack + hindex);
	}
	return (0);
}

/**
 * str_concat - string concatenate
 * Description: concatenates two strings into a newly created string
 * @s1: string one
 * @s2: string two
 * Return: Pointer to new string
 */

char *str_concat(char *s1, char *s2)
{
	int s1_size, s2_size, srcindex, dstindex;
	char *dst;


	s1_size = _strlen(s1);
	s2_size = _strlen(s2);
	dst = malloc(s1_size + s2_size + 1);

	if (dst == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		for (srcindex = 0, dstindex = 0; *(s1 + srcindex);
		     srcindex ++, dstindex++)
			*(dst + dstindex) = *(s1 + srcindex);
	}
	if (s2 != NULL)
	{
		for (srcindex = 0; *(s2 + srcindex); srcindex++, dstindex++)
			*(dst + dstindex) = *(s2 + srcindex);
	}
	*(dst + dstindex) = '\0';

	return (dst);
}

/**
 * _strlen - string length
 * Description: Gets the length of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	int size = 0;

	if (s == NULL)
		return (0);

	while (*(s + size))
		size++;

	return (size);
}
