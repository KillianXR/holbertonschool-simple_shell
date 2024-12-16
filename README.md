# Simple Shell

**AUTHORS:** Gabriel Bescond, Killian Lemoine

---

## Description

This project is about creating a simple UNIX command interpreter, also known as a shell. The shell should be able to accept user input, execute basic commands, and handle simple errors.

### Concepts
- Unix shell concepts
- Process management
- System calls
- Input/output handling
- Error management

---

### General
- Allowed editors: vi, vim, emacs
- All files must be compiled on Ubuntu 20.04 LTS using `gcc`, with the following options: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- A `README.md` file is mandatory
- Your code should follow the Betty style guide. It will be checked using `betty-style.pl` and `betty-doc.pl`
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All header files should be include-guarded
- Use system calls only when necessary
- GitHub repository should be created for the group

---

Allowed Functions and System Calls
The following functions and system calls are allowed:

All functions from string.h
access, chdir, close, execve, exit, _exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, printf, 
fprintf, vfprintf, sprintf, putchar, read, readdir, signal, stat, lstat, fstat, strtok, wait, waitpid, wait3, wait4, write

## Tasks
0. README, man, AUTHORS
Write a README.md file
Write a man page for your shell
Include an AUTHORS file listing all contributors

1. Betty would be proud
Write beautiful code that passes the Betty checks.

2. Simple shell 0.1
Create a basic UNIX command line interpreter that:
Displays a prompt and waits for the user to type a command
Displays the prompt again after a command is executed
Handles "end of file" condition (Ctrl+D)
Displays an error message when a command cannot be found

3. Simple shell 0.2
Handle command lines with arguments

4. Simple shell 0.3
Handle the PATH for finding executable programs

5. Simple shell 0.4
Implement the exit built-in command

6. Simple shell 1.0
Implement the env built-in command to print the current environment
