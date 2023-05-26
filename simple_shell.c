#include "main_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_prompt(const char *prompt)
{
    if (write(STDOUT_FILENO, prompt, strlen(prompt)) == -1)
    {
        perror("Error: write");
        exit(EXIT_FAILURE);
    }
}

char *read_input()
{
    char *buf = NULL;
    size_t len = 0;
    ssize_t nread;
    int line_count = 0;

    nread = getline(&buf, &len, stdin);
    if (nread == -1)
    {
        /*perror();*/
        free(buf);
        exit(EXIT_FAILURE);
    }
    else if (nread > 0 && buf[nread - 1] == '\n')
    {
        buf[nread - 1] = '\0';
    }
	 /* Update line count*/
    while (nread > 0) {
        if (buf[nread - 1] == '\n') {
            line_count++;
        }
        nread--;
    }

    return buf;
}

char **split_input(char *input, int *word_count)
{
    const char *delimiter = " \n";
    char *token;
    char **argv;
    int i = 0;

    token = strtok(input, delimiter);
    while (token != NULL)
    {
        (*word_count)++;
        token = strtok(NULL, delimiter);
    }
    (*word_count)++;

    argv = malloc(sizeof(char *) * (*word_count));
    if (argv == NULL)
    {
        perror("Error: memory allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, delimiter);
    while (token != NULL)
    {
        argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
        if (argv[i] == NULL)
        {
            perror("Error: memory allocation error");
            exit(EXIT_FAILURE);
        }
        strcpy(argv[i], token);
        token = strtok(NULL, delimiter);
        i++;
    }
    argv[i] = NULL;

    return argv;
}

void execute_command(char **argv)
{
	char *cmd = NULL, *cmd_main = NULL;
    pid_t pid;
    int status;
    int i = 0;

    while (argv[i] != NULL)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("Error: fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
	    cmd = argv[i];
        /* generate the path b4 taking it to execve */
                cmd_main = getPath(cmd);

        /* Child process*/
        if (execve(cmd_main, argv, environ) == -1)
            {
		    if (errno == EACCES)
				exit(126);
			exit(1);
            }
        }
        else
        {
            /* Parent process*/
            if (waitpid(pid, &status, 0) == -1)
            {
                perror("Error: waitpid");
                exit(EXIT_FAILURE);
            }
        }
        i++;
    }
}

void free_argv(char **argv)
{
	int i = 0;
    if (argv == NULL)
    {
        return;
    }

    while (argv[i] != NULL)
    {
        free(argv[i]);
	i++;
    }
    free(argv);
}

int main(int argc, char **argv)
{
    char *buf;
    char *prompt = "$ ";
    int word_count;
    char **tokens;
    (void) argc;
    (void) argv;
    /*Start at index 1 to skip the program name*/

    while (1)
    {
	    print_prompt(prompt);
        fflush(stdout);
	word_count = 0;

        buf = read_input();
        tokens = split_input(buf, &word_count);
	/* Check if the input is empty*/
        if (tokens[0] == NULL)
        {
            free_argv(tokens);
            free(buf);
            continue;
        }
	/* Check for the special command: "exit"*/
        if (_strcmp(tokens[0], "exit") == 0)
        {
            free_argv(tokens);
            free(buf);
            break;
        }
        execute_command(tokens);

        free_argv(tokens);
        free(buf);
    }

    return (0);
}

