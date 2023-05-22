#include <stdio.h>
#include "main_shell.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *forkWaitExecute - fork & wait &execute example
 *@words: The array of the arguments
 *
 * Return: Always 0.
 */
int forkWaitExecute(char **words)
{
	pid_t child_pid;
	int status;
	int i = 0;

	while (words[i] != NULL)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("Wait for me, wait for me\n");
			sleep(3);

			printf("Before execve\n");
			if (execve(words[0], words, NULL) == -1)
			{
				perror("Error:");
			}
			printf("After execve\n");
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				printf("Child process ID %d exited with status: %d\n",
						child_pid, WEXITSTATUS(status));
			}
			else
			{
			printf("Child process ID %d terminated abnormally\n", child_pid);
			}
		}
	i++;
	}
	return (0);
}


/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * my_getline - buffers chained commands
 * @buff: address of buffer
 * @length: address of len var
 *
 * Return: 0
 */

ssize_t my_getline(char **buff, size_t *length)
{
	ssize_t nread = 0;
	ssize_t position = 0;
	int n;

	if (!buff || !length)
	{
		return (-1);
	}
	if (!*buff || *length == 0)
	{
		*length =  128;
		*buff = malloc(*length);
		if (!*buff)
		{
			return (-1);
		}
	}
	while ((n = getchar()) != '\n' && n != EOF)
	{
		if (position >= (ssize_t)(*length) - 1)
		{
			*length *= 2;
			char *buff_new = realloc(*buff, *length);

			if (!buff_new)
				return (-1);
			*buff = buff_new;
		}
		(*buff)[position++] = n;
	}
	if (n == EOF || length == 0)
		return (-1);

	(*buff)[position] = '\0';
		return (nread);
}

/**
 * main - buffers chained commands
 * @argc: address of buffer
 * @argv: address of len var
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *buf = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		nread = my_getline(&buf, &len);

	if (nread != -1)
	{
		if (nread > 0 && buf[nread - 1] == '\n')
			buf[nread - 1] = '\0';
		char **words = strtow(buf);

		if (words != NULL)
		{
			forkWaitExecute(words);
			free(words);
		}
		else
		{
			printf("Memory allocation failed.Input a valid arg\n");
		}
		printf("%s\n", buf);
	}
	else
	{
		printf("End of input (EOF) reached.\n");
		break;
	}
	}
	free(buf);
	return (0);
}
