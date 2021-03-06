#include "holberton.h"

/**
 * free_array - free an array of pointers
 * Description: Frees an array of pointers
 * @tokens: Pointer to array of pointers to free
 */
void free_array(char **tokens)
{
	int index = 0;

	while (tokens[index])
	{
		free(tokens[index]);
		index++;
	}
	free(tokens);
}
/**
 * token_count - count number of tokens
 * Description: Counts the number of tokens in a string
 * @str: String to parse
 * @delims: string of characters that separate tokens
 * Return: Number of tokens
 */
int token_count(char *str, char *delims)
{
	int tokens = 0, index = 0;
	char prev = 0;

	while (str[index])
	{
		if (!_strchr(delims, str[index]) &&
		    (_strchr(delims, prev) || index == 0))
			tokens++;
		prev = str[index];
		index++;
	}
	return (tokens);
}

/**
 * _strtok - tokens from string
 * Description: Parses a string to extract all tokens and store them in
 *              an array
 * @str: String to parse
 * @delims: string of characters that separate tokens
 * @params: Parameter struct
 * Return: Pointer to array of tokens
 */
char **_strtok(char *str, char *delims, param_t *params)
{
	char **tokens;
	int t_index = 0, s_index = 0, token_len;
	char prev = 0;

	if (token_count(str, delims) == 0)
		return (NULL);
	tokens = malloc((token_count(str, delims) + 1) * sizeof(char *));
	if (!tokens)
		clean_exit(params, EXIT_FAILURE);
	while (str[s_index])
	{
		if (!_strchr(delims, str[s_index])
		    && (_strchr(delims, prev) || s_index == 0))
		{
			token_len = 0;
			while (str[token_len + s_index] &&
			       !_strchr(delims, str[token_len + s_index]))
				token_len++;
			tokens[t_index] = malloc(token_len + 1);
			if (!tokens[t_index])
			{
				free_array(tokens);
				clean_exit(params, EXIT_FAILURE);
			}
			tokens[t_index][token_len] = 0;
			while (token_len-- > 0)
				tokens[t_index][token_len] =
					str[s_index + token_len];
			t_index++;
		}
		prev = str[s_index];
		s_index++;
	}
	tokens[t_index] = NULL;
	return (tokens);
}
