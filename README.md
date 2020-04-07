# Simple Shell
Description coming soon.

## Mandatory
### Handles:
Basic functionality
PATH
exit

### To Do:
Parse env for PS1 for prompt, default to '$ ' if not found
Create 'env' built in. 'env' currently works but as a command, not a built-in
Create functions that generates and writes proper error codes (ex. ./shell: No such file or directory)
Actual README
Man page
Blog post (ls -l?)


## Advanced
### Done:
Custom strtok

### To Do:
Test Suite?
Custom getline
Handle arguments for exit built-in
Handle Ctrl+C: Your shell should not quit when the user inputs ^C
Handle sentenv and unsetenv built-ins
Handle the cd built-in
Handle commands separator (;)
Handle && and || shell logical operators
Handle alias built-in
Handle variables replacement, $?, $$
Handle comments (#)
Handle help built-in
Handle history built-in, without arguments
Handle file as input
