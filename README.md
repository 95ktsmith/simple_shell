# Holberton Shell - Simple Shell

## Description

Holberton Shell (hsh) is a simple command line interpreter for a Unix environment. WIthin this
repository are all the file required for the shell to be compiled and run, as well as man and author pages.

## How to Use
### Compilation
The shell is compiled this way:
`gcc -Wall -Werror -Wextra -pedanctic *.c -o hsh`

### Interactive Mode
To start interactive mode, type the following into the terminal:

`./hsh`

From here, input any commands you would like executed. For example:
```
$ echo "Hello world!"
Hello World!
$
```
Or try a command with additional options, like:
```
$ ls -l
total 132
-rw-rw-r-- 1 vagrant vagrant   181 Apr  7 01:19 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  1525 Apr 15 13:44 builtins_1.c
-rw-rw-r-- 1 vagrant vagrant  2148 Apr 15 03:39 errorfuncs.c
-rw-rw-r-- 1 vagrant vagrant  1454 Apr 15 03:39 ffree.c
-rw-rw-r-- 1 vagrant vagrant   966 Apr 16 10:50 getargs.c
-rw-rw-r-- 1 vagrant vagrant  3647 Apr 16 10:50 _getenv.c
-rw-rw-r-- 1 vagrant vagrant  2276 Apr 16 10:50 holberton.h
-rw-rw-r-- 1 vagrant vagrant  2688 Apr 15 03:39 list_funcs.c
-rw-rw-r-- 1 vagrant vagrant  2611 Apr 16 10:50 main.c
-rw-rw-r-- 1 vagrant vagrant 29334 Apr 16 10:50 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant  3163 Apr 16 10:50 README.md
-rw-rw-r-- 1 vagrant vagrant  2562 Apr 15 03:39 strfuncs.c
-rw-rw-r-- 1 vagrant vagrant  1947 Apr 16 10:50 _strtok.c
$
```
To exit interactive mode:
```
ksmith:$ ./hsh
$ exit
ksmith:$
```

### Non-Interactive Mode
To start in non-interactive mode, the shell is used as:
`echo [commands] | ./hsh`

For example:
```
ksmith:$ echo "echo Hello!" | ./hsh
Hello!
ksmith:$
```
When used this way, the shell does not need to be exited, as it will exit itself
after executing any commands given.
