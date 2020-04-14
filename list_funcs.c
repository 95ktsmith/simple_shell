#include "holberton.h"

/**
 * _getenv_node - get environment value from node
 * Description: Searches the environment list for a node containing a
 *              string that matches the var string given, and returns its value
 * @var: Name of the variable to look for
 * @head: Head of the linked list
 * Return: Pointer to the value string if found, or NULL if not found.
 */
char *_getenv_node(char *var, env_t *head)
{
	while (head)
	{
		if (_strcmp(head->var, var) == 0)
			return (head->val);
		head = head->next;
	}
	return (NULL);
}

/**
 * env_to_list - environment to list
 * Description: Copies the information from the environment array into a linked
 *              list of struct env_nodes (env_t).
 * @env: Environment to copy
 * Return: Head of the list
 */
env_t *env_to_list(char *env[])
{
	env_t *head = NULL;
	int env_index, line_index;
	char *var, *val;

	if (!env)
		return (NULL);

	for (env_index = 0; env[env_index]; env_index++)
	{
		var = env[env_index];
		for (line_index = 0; env[env_index][line_index]; line_index++)
		{
			if (env[env_index][line_index] == '=')
				break;
		}
		if (env[env_index][line_index] != '=')
			return (NULL);
		val = &(env[env_index][line_index + 1]);
		env[env_index][line_index] = 0;

		if (add_env_node(&head, var, val) == NULL)
		{
			free_env(head);
			return (NULL);
		}
	}
	return (head);
}

/**
 * add_env_node - add environment node
 * Description: Adds a node at the end of the environment list with the given
 *              variable and its value.
 * @head: Head of the list
 * @var: Name of the variable
 * @val: The value it should contain
 * Return: Address of the added node, or NULL if it fails.
 */

env_t *add_env_node(env_t **head, char *var, char *val)
{
	env_t *new_node;
	env_t *start;

	new_node = malloc(sizeof(env_t));
	if (!new_node)
		return (NULL);
	new_node->var = _strdup(var);
	if (!new_node->var)
	{
		free(new_node);
		return (NULL);
	}
	new_node->val = strdup(val);
	if (!new_node->val)
	{
		free(new_node->var);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;

	if (!(*head))
		*head = new_node;
	else
	{
		start = *head;
		while ((*head)->next)
			*head = (*head)->next;
		(*head)->next = new_node;
		*head = start;
	}
	return (new_node);
}

/**
 * _strcmp - String compare
 * Description: Compares two strings to check if they are exactly the same
 * @s1: String 1
 * @s2: String 2
 * Return: 1 if they are the same, or 0 if they are different
 */

int _strcmp(char *s1, char *s2)
{
	int index;

	index = 0;

	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	if (s1[index] || s2[index])
		return (0);
	return (1);
}
