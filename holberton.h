#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>

/**
 * struct params - parameter struct
 * @loop_count: Number of loops or inputs since the shell was started
 * @status: Status for exiting, set after each user input
 * @shellname: Name of the file the shell was run as
 * @args: Tokenized list of arguments from getline
 * @env: Environment
 */
typedef struct params
{
	size_t loop_count;
	int status;
	char *shellname;
	char **args;
	char **env;
} param_t;

/**
 * struct env_node - Environment node struct
 * @var: Envrionment variable name
 * @val: Variable value
 * @next: Next node in linked list
 */
typedef struct env_node
{
	char *var;
	char *val;
	struct env_node *next;
} env_t;

/**
 * struct builtin - Builtin function struct
 * @name: Name of the builtin command
 * @f: The Function associated with that name
 */
typedef struct builtin
{
	char *name;
	void (*f)(param_t *params);
} builtin_t;

/* main */
int find_and_exec(param_t *params);
void (*get_builtin(char *name))(param_t *params);

/* builtins_1 */
void exit_shell(param_t *params);
void print_env(param_t *params);

/* _getenv */
char *check_file(param_t *params);
char *find_in_path(param_t *params);
char *_getenv(char *var, char *env[]);
char *find_in_pwd(param_t *params);

/* ffree */
void free_params(param_t *params);
void clean_exit(param_t *params, int status);
void free_env(env_t *head);
void ffree(const char *fmt, ...);

/* getargs */
char **getline_to_args(ssize_t *nbytes, FILE *stream, param_t *params);

/* listfuncs */
size_t _pow(size_t a, size_t b);
int _strcmp(char *s1, char *s2);
env_t *env_to_list(char *env[]);
env_t *add_env_node(env_t **head, char *var, char *val);
char *_getenv_node(char *var, env_t *head);

/* error funcs */
size_t _pow(size_t a, size_t b);
void stoa(size_t value, char *buffer, size_t base);
ssize_t write_error(param_t *params, char *msg);

/* strfuncs */
char *_strdup(char *);
char *_strchr(char *, char);
char *_strstr(char *haystack, char *needle);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);

/* _strtok */
int token_count(char *str, char *delims);
char **_strtok(char *str, char *delims, param_t *params);
void free_array(char **tokens);

#endif /* _HOLBERTON_H_ */
