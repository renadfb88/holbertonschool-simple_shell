# Simple Shell Project (hsh)

A simple UNIX command line interpreter implemented in C as part of the Holberton School curriculum.

---

## Description
`hsh` is a minimalistic shell that mimics the basic behavior of `/bin/sh`. It can execute external system commands by locating them via the `PATH` environment variable or direct paths, handles interactive and non-interactive execution modes, and manages process execution using system calls like `fork`, `execve`, and `wait`.

---

## Features
- Interactive and Non-interactive modes
- Command execution with arguments
- Path resolution via `PATH`
- Handling `EOF` (Ctrl+D)
- Built-in commands: `exit`, `env`

---

## How it works

Every time you type a line, the shell does five things:

1. **Prompt** - print `#cisfun$ ` and wait for you.
2. **Read** - read the whole line you typed.
3. **Split** - cut the line into words, so `ls -l` becomes `ls` and `-l`.
4. **Find** - turn the word `ls` into a real program, `/bin/ls`, by searching
   the directories listed in your `PATH`.
5. **Run** - make a copy of itself (`fork`), turn the copy into that program
   (`execve`), and wait for it to finish (`wait`).

Then it starts again from step 1.

---

## Compilation
Compile all `.c` files using `gcc`:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

---

## Running it

You can type commands yourself:

```
$ ./hsh
#cisfun$ ls
AUTHORS  README.md  hsh  main.c  parser.c  path.c  shell.h
#cisfun$ ls -l /tmp
#cisfun$ exit
$
```

Press `Ctrl+D` at any time to leave the shell.

Or you can feed it commands from somewhere else. When the input is not a
keyboard, no prompt is printed:

```
$ echo "/bin/ls" | ./hsh
AUTHORS  README.md  hsh  main.c  parser.c  path.c  shell.h
```

---

## Built-in commands

Two commands are handled by the shell itself, without starting a new program:

| Command | What it does |
| --- | --- |
| `exit` | Leaves the shell. |
| `env` | Prints your environment, one `NAME=value` per line. 

```

## When a command does not exist

`hsh` prints the same error `/bin/sh` does, and keeps going:

```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
```

The `1` is the line number, and the name at the front is however you started
the shell.

---

## The files

| File | What is inside |
| --- | --- |
| `shell.h` | The header: includes and all the function prototypes. |
| `main.c` | `main()` (the loop) and `execute_cmd()` (fork, exec, wait). |
| `parser.c` | Reading a line and splitting it into words. |
| `path.c` | Searching `PATH` to find the program. |
| `builtins.c` | The `exit` and `env` commands. |

---

## Manual page

```bash
man ./man_1_simple_shell
```

---

## Authors

- Arwa Ahmed Alhamrani
- Renad Fouad Albatat
