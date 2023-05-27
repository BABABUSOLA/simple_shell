README for the simple shell project

#PID & PPID

Exercise 0a: Run `gcc -Wall -Werror -pedantic pid.c -o mypid && ./mypid` to get the process id and it must be different each time you run it
Exercise 0b: Run `gcc -Wall -Werror -pedantic my_parent_pid.c -o myparentpid && ./myparentpid` to get the parent process id and it must be the same response as `ECHO $$`

Exercise 1: Run `./pid_max` to the get maximum number processes

#ARGUMENTS

Exercise 0: Run `gcc -Wall -Wextra -Werror -pedantic get_arg.c -o get_arg && ./get_arg arg1 arg2 arg3` to get the list processes.

Exercise 1a: Run `gcc -Wall -Wextra -Werror -pedantic prompt.c -o prompt && ./prompt`, this will open a $ sign words can be typed, pressing enter, displays the text typed, to exit in VI, use Ctrl+c

Exercise 1b: Run `gcc -Wall -Wextra -Werror -pedantic _getline.c prompt.c -o prompt && ./prompt`. this is different from 1a as I am using my getline line function instead of the built in get line function.

Run `gcc -Wall -Wextra -Werror -pedantic prompt.c -o prompt && ./prompt`, this is different from 1b as I am using my getline line function instead of the built in get line function in the same file

Exercise 2a: Run `gcc -Wall -Wextra -Werror -pedantic getString.c -o getString && ./getString`, this will generate a response without the use of strok.
Exercise 2b: Run `gcc -Wall -Wextra -Werror -pedantic _strArray.c prompt.c -o prompt && ./prompt

#Executing a program

Run `gcc -Wall -Wextra -Werror -pedantic exec.c -o exec && ./exec`

#Creating Processes

Run `gcc -Wall -Wextra -Werror -pedantic fork.c -o fork && ./fork`

#Wait
Run `gcc -Wall -Wextra -Werror -pedantic wait.c -o wait && ./wait`

#Exercise: fork + wait + execve

Run `gcc -Wall -Wextra -Werror -pedantic forkWaitExec.c -o forkWaitExec && ./forkWaitExec`

#Exercise: super simple shell

Run `gcc -Wall -Wextra -Werror -pedantic shell.c -o shell && ./shell`, then when the prompt is displayed type the command of your choice, e.g: /bin/ls or ./{anyexecutablefile available in the folder} i.e ./myparentpid

#Exercise: fie information

Run `gcc -Wall -Wextra -Werror -pedantic stat.c -o stat`, to create the stat file, then run, `./stat ls /bin/ls /usr/bin/ls`, this then runs the file start with the 3 arguments ls /bin/ls and /usr/bin/ls

#Exercise: Environment

Exercise 0: Run `gcc -Wall -Werror -pedantic env-main.c -o printenv && ./printenv` this will generate the environment variable available using the global variable

Exercise 1: Run `gcc -Wall -Werror -pedantic env.c -o printenv && ./printenv` this will generate the environment variable available using the global variable and also the address of the env from main and the env from the environ and they are the same result



## HSH

# List of allowed functions:

`List of allowed functions and system calls`
`access (man 2 access)`
`chdir (man 2 chdir)`
`close (man 2 close)`
`closedir (man 3 closedir)`
`execve (man 2 execve)`
`exit (man 3 exit)`
`_exit (man 2 _exit)`
`fflush (man 3 fflush)`
`fork (man 2 fork)`
`free (man 3 free)`
`getcwd (man 3 getcwd)`
`getline (man 3 getline)`
`getpid (man 2 getpid)`
`isatty (man 3 isatty)`
`kill (man 2 kill)`
`malloc (man 3 malloc)`
`open (man 2 open)`
`opendir (man 3 opendir)`
`perror (man 3 perror)`
`read (man 2 read)`
`readdir (man 3 readdir)`
`signal (man 2 signal)`
`stat (__xstat) (man 2 stat)`
`lstat (__lxstat) (man 2 lstat)`
`fstat (__fxstat) (man 2 fstat)`
`strtok (man 3 strtok)`
`wait (man 2 wait)`
`waitpid (man 2 waitpid)`
`wait3 (man 2 wait3)`
`wait4 (man 2 wait4)`
`write (man 2 write)`

# To run the shell

Run `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh && ./hsh`

## Output

Unless specified otherwise, your program must have the exact same output as `sh (/bin/sh)` as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your `argc[0]

## Test script

Run `./check.sh | less -r`, if all is successful then the checker passed it all

## Authors

Run the `authors` file, there is a bash script that generates the AITHORS file.


