# Simple Shell

## Description

* A simple UNIX command line interpreter, or shell.

## Project tasks :computer:


### Authorized functions and system calls

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

### Compilation

*The shell will be compiled this way:*
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Mandatory
### Handles:
Basic functionality\
PATH\
exit\
Parse env for PS1\
Correct error outputs (builtins?)\
env

### To Do:

* [Shell man page](./man_1_simple_shell)

Blog post (ls -l?)


## Advanced
### Done:
Custom strtok\
Comments (#)\
Should not quit on Ctrl-C (Kind of done. Doesn't quit but doesn't reprint
prompt.)\
Handle arguments to exit

### To Do:
[Test Suite](https://github.com/AmilcarArmmand/shell_test_suite)
Custom getline\
Handle sentenv and unsetenv built-ins\
Handle the cd built-in\
Handle commands separator (;)\
Handle && and || shell logical operators\
Handle alias built-in\
Handle variables replacement, $?, $$\
Handle help built-in\
Handle history built-in, without arguments\
Handle file as input


AUTHORS
builtins_1.c
errorfuncs.c
ffree.c
getargs.c
_getenv.c
holberton.h
list_funcs.c
main.c
man_3_simple_shell
README.md
shell
strfuncs.c
_strtok.c
