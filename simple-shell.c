#include "main_shell.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

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
	(void)**argv;
	char *buf = NULL, *buf_copy = NULL, *prompt = "$ ";
	size_t len = 0;
	ssize_t nread;
	const char *delimiter = " \n";
	int word_count = 0;
	chart *words;
	int i;

	while (1)
	{
		if(isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, prompt, 2);
		}
		fflush(stdout);
	#if USE_GETLINE
		nread = getline(&buf, &len, stdin);
	#else
		nread = my_getline(&buf, &len);
	#endif
	if (nread == -1)
	{
		perror("Error (getline)");
		free(buf);
		exit(EXIT_FAILURE);
	}
	buf_copy = malloc(sizeof(char) * nread);
	if (!buf_copy)
	{
		perror("Error: memmory allocation error");
		exit(EXIT_FAILURE);
	}
	/*copy buf to buf_copy */
	strcpy(buf_copy, buf);
	/*calculate the toal number of tokens*/
	words = strtok(buf, delimiter);

	while (words != NULL)
	{
		word_count++;
		words = strtok(NULL, delimiter);
	}
	word_count++;

	/*Allocate space to hold the arrau of strings */
	argv = malloc(sizeof(char *) * word_count);

	/*store each token in the argv array */
	words = strtok(buf_copy, delim);

	while (words != NULL)
	{
		argv[i] = malloc(sizeof(char) * (strlen(words) + 1));
		strcpy(argv[i], words);
		words = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;

	/*execute the command*/
	executer(argv);
	
	}
	/*free up allocated memory*/
	free(buf_copy);
	free(buf);
	return (0);
}
