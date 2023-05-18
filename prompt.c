#include <stdio.h>
#include "main_shell.h"
/**
 * input_buf - buffers chained commands
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

		printf("%s\n", buf);
	}

	else
	{
		if (nread == -1)
		{
			printf("End of input (EOF) reached.\n");
		}
		else
		{
			printf("Error reading input.\n");
		}
		break;
	}
	}

	free(buf);
	return (0);
}

