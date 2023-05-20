#include <stdio.h>
#include "main_shell.h"

/**
 * freeWords - provide the memory allocated
 * @words: the input string
 * @wordCount: integer that store number of words found
 *
 * Return: 0
 */

void freeWords(char **words, int wordCount)
{
	for (int i = 0; i < wordCount; i++)
	{
		free(words[i]);
	}
	free(words);
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
		printf("$ ");
		fflush(stdout);
		nread = my_getline(&buf, &len);

	if (nread != -1)
	{
		if (nread > 0 && buf[nread - 1] == '\n')
			buf[nread - 1] = '\0';
		int wordCount;
		char **words = splitString(buf, &wordCount);

		if (words != NULL)
		{
			printf("Number of words: %d\n", wordCount);
			for (int i = 0; i < wordCount; i++)
			{
				printf("Word %d: %s\n", i + 1, words[i]);
			}
			freeWords(words, wordCount);
		}
		else
		{
			printf("Memory allocation failed.\n");
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
