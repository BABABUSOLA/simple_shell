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
