#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
extern char** environ;
int main()
{
	unsigned int i;
	char **env = environ;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
