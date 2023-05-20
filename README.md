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
