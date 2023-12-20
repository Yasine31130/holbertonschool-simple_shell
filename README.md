![Holberton school image](https://apply.holbertonschool.com/holberton-logo.png)
# C - Simple Shell

The goal of the simple shell project is to create our own simplified version of a UNIX command interpreter in C language.

## Installation

To run our simple shell, follow these steps : 

  1- Clone the repository https://github.com/Yasine31130/holbertonschool-simple_shell
  
  2- Compile the program with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

  3- Run the program with `./hsh`

## Man Page 

To access [the man page](https://github.com/Yasine31130/holbertonschool-simple_shell/blob/master/man_1_simple_shell), run `man ./man_1_simple_shell`

## Requirements

- The program must be compiled with gcc (GNU Compiler Collection).

- The code must be in Betty style.
## Allowed functions

-   all functions from strings.h
-   `access`  (man 2 access)
-   `chdir`  (man 2 chdir)
-   `close`  (man 2 close)
-   `closedir`  (man 3 closedir)
-   `execve`  (man 2 execve)
-   `exit`  (man 3 exit)
-   `_exit`  (man 2 _exit)
-   `fflush`  (man 3 fflush)
-   `fork`  (man 2 fork)
-   `free`  (man 3 free)
-   `getcwd`  (man 3 getcwd)
-   `getline`  (man 3 getline)
-   `getpid`  (man 2 getpid)
-   `isatty`  (man 3 isatty)
-   `kill`  (man 2 kill)
-   `malloc`  (man 3 malloc)
-   `open`  (man 2 open)
-   `opendir`  (man 3 opendir)
-   `perror`  (man 3 perror)
-   `printf`  (man 3 printf)
-   `fprintf`  (man 3 fprintf)
-   `vfprintf`  (man 3 vfprintf)
-   `sprintf`  (man 3 sprintf)
-   `putchar`  (man 3 putchar)
-   `read`  (man 2 read)
-   `readdir`  (man 3 readdir)
-   `signal`  (man 2 signal)
-   `stat`  (__xstat) (man 2 stat)
-   `lstat`  (__lxstat) (man 2 lstat)
-   `fstat`  (__fxstat) (man 2 fstat)
-   `strtok`  (man 3 strtok)
-   `wait`  (man 2 wait)
-   `waitpid`  (man 2 waitpid)
-   `wait3`  (man 2 wait3)
-   `wait4`  (man 2 wait4)
-   `write`  (man 2 write)
## Features

- Displays a prompt and waits for the user to type a command in.
- The prompt is displayed again each time a command has been executed.
- Handles arguments.
- Handles errors.
- Handles the “end of file” condition (Ctrl+D).
- Handlebuilt-in commands : 
    - `env` : to print the environment
    - `exit` : to exit the program
## Usage examples
In interactive mode :

```
$ ./hsh
$ /bin/ls
hsh main.c main.h args.c exec.c exec_err.c man_1_simple_shell path.c
$ exit
```
In non-interactive mode :

```
$ ls
script_mode.txt hsh main.c main.h args.c exec.c exec_err.c man_1_simple_shell path.c
$ cat script_mode.txt
ls
/bin/ls
echo "coucou"
$ ./hsh < script_mode.txt
script_mode.txt hsh main.c main.h args.c exec.c exec_err.c man_1_simple_shell path.c
script_mode.txt hsh main.c main.h args.c exec.c exec_err.c man_1_simple_shell path.c
coucou
```
Errors handling :

```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
```
## Files

|**File name**|**Description**|
|:-------|:---------:|
|`main.c`|The main function gets the comand user line input.|
|`args.c`|Tokenizes the commands into arguments and contains the function to print the environment.|
|`exec.c`| It executes the command arguments.|
|`exec_err.c`|Handles failures for the command executions.|
|`_getenv.c`|Custom `getenv` function not allowed.|
|`path.c`|Handles the path when user input doesn't contain it.|
|`main.h`|Header file, contains libraries used, macros and prototypes.|


## Authors

- [@mathpvx](https://github.com/mathpvx)
- [@Yasine31130](https://github.com/Yasine31130)

