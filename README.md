# Holberton Shell - Simple Shell

## Description

* Holberton Shell (hsh) is a simple command line interpreter for a Linux environment.

## Project tasks  :computer:


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

The shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

### Quick start guide

To start interactive mode, type the following into the terminal:

`./hsh`

### Testing

**In interactive mode:**
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

**In non-interactive mode:**
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Repository contents

* [AUTHORS](./AUTHORS)
* [README.md](./README.md)
* [_getenv.c](./_getenv.c)
* [_strtok.c](./_strtok.c)
* [builtins_1.c](./builtins_1.c)
* [errorfuncs.c](./errorfuncs.c)
* [ffree.c](./ffree.c)
* [getargs.c](./getargs.c)
* [holberton.h](./holberton.h)
* [list_funcs.c](./list_funcs.c)
* [main.c](./main.c)
* [man_1_hsh](./man_1_hsh)
* [strfuncs.c](./strfuncs.c)

## Mandatory tasks  :wrench:

* Coding style used is [Betty](./https://github.com/holbertonschool/Betty/wiki) style.
Basic functionality\
PATH\
exit\
Parse env for PS1\
Correct error outputs (builtins?)\
env


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
