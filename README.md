# Simple Shell Project

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Requirements](#requirements)
4. [Compilation](#compilation)
5. [Functionality](#functionality)
6. [Usage](#usage)
7. [Functions and System Calls](#functions-and-system-calls)
8. [How It Works](#how-it-works)
9. [File Descriptions](#file-descriptions)
10. [Examples](#examples)
11. [Authors](#authors)

---

## Introduction

This project is a simple UNIX command-line interpreter, or shell, developed as part of the Holberton School curriculum. The shell replicates basic functionalities of `/bin/sh` and provides an environment where users can execute commands interactively or in non-interactive mode.

---

## Features

- Executes commands interactively and non-interactively.
- Parses user input and tokenizes it into commands and arguments.
- Searches for executable programs.
- Handles basic errors, such as "command not found."
- Does not allow memory leaks.

---

## Requirements

### General

- **Editors:** `vi`, `vim`, `emacs`
- **OS:** Ubuntu 20.04 LTS
- **Compiler:** `gcc` with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Style:** Betty coding style checked with `betty-style.pl` and `betty-doc.pl`
- **Output:** Matches `/bin/sh` exactly except for the program name in error messages.
- **Memory:** No memory leaks are allowed.
- **File Structure:** No more than 5 functions per file, and all headers must have include guards.
- **GitHub Repository:** Must follow project guidelines.

### Allowed Functions and System Calls

- All functions from `string.h`
- `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`, `fflush`, `fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`, `kill`, `malloc`, `open`, `opendir`, `perror`, `printf`, `fprintf`, `vfprintf`, `sprintf`, `putchar`, `read`, `readdir`, `signal`, `stat`, `lstat`, `fstat`, `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`

---

## Compilation

The shell is compiled with the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Functionality

### Interactive Mode

The shell runs interactively when executed directly:

```bash
$ ./hsh
❓ UnknownCommand> ls
file1 file2 file3
❓ UnknownCommand>
exit
```

### Non-Interactive Mode

The shell can also process commands piped into it:

```bash
$ echo "ls" | ./hsh
file1 file2 file3
```

---

## Usage

1. Clone the repository to your local machine.
2. Compile the program using the provided compilation command.
3. Run the program interactively by executing `./hsh` or non-interactively using pipes.
4. To check for memory leaks, use `valgrind`:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./hsh
```

---

## Functions and System Calls

### `splitline`

#### Description

Divides a command line input into tokens (commands and arguments).

#### Prototype

```c
char **_splitline(char *line)
```

#### Functionality

- Tokenizes the input string using delimiters (space, tab, etc.).
- Allocates memory dynamically for tokens.
- Returns an array of strings representing the command and its arguments.

#### Example

Input:

```bash
ls -l /home
```

Output:

```c
["ls", "-l", "/home", NULL]
```

### `main`

#### Description

Serves as the entry point for the shell. Handles user input, executes commands, and manages processes.

#### Functionality

- Displays a prompt in interactive mode.
- Reads input using `getline`.
- Tokenizes input with `splitline`.
- Forks a child process and executes commands with `execve`.
- Waits for the child process to terminate before returning to the prompt.
- Handles errors and exits gracefully.

---

## How It Works

1. **Initialization**: The shell starts by displaying a prompt (if interactive).
2. **Input Handling**: Reads input from the user via `getline`.
3. **Parsing**: Uses `splitline` to tokenize the input.
4. **Execution**: Searches for the command in \_execute.c, forks a process, and executes the command with `execve`.
5. **Error Handling**: Prints appropriate error messages.
6. **Termination**: The shell exits when the user types `exit` or EOF.

---

## File Descriptions

- `simple_shell.c`: Contains the main function and core shell logic.

- \_`splitline.c`: Implements the `splitline` function.

- \_`execute.c`: Handles command execution.

- `main.h`: Header file with prototypes and macros.

---

## Examples

Interactive Mode:

```bash
$ ./hsh
❓ UnknownCommand> /bin/pwd
/home/user
❓ UnknownCommand> /bin/ls
file1 file2 file3
❓ UnknownCommand> exit
```

Non-Interactive Mode:

```bash
$ echo "/bin/ls" | ./hsh
file1 file2 file3
```

---

## Authors

- Gabriel Bescond
- Killian Lemoine


