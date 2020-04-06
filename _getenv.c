#include "holberton.h"
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
 * _strlen - Returns lenght of a string
 * @s: Incoming string
 * Description: Counts the number of charaters in a string, returns that number
 * Return: Length of the string
 */

int _strlen(char *s)
{
	int strlen = 0;

	while (s[strlen])
		strlen++;

	return (strlen);
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
 * _getenv - get environment variable
 * Description: Searches the env array of strings for the specified variable
 * @var: The variable to search for
 * @env: Environment
 * Return: A pointer to the first byte following the '=' in that line if the
 *         variable is found, or NULL if it is not found.
 */
char *_getenv(char *var, char **env)
{
	int index = 0;

	while (env[index])
	{
		if (_strstr(env[index], var) != NULL)
			return (_strstr(env[index], var) + _strlen(var) + 1);
		index++;
	}
	return (NULL);
}
