#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
extern char** environ;
int main(int argc, char **argv, char **env)
{
	unsigned int i;

	i = 0;
	printf("Address of env: %p\n", (void*)env);
	printf("Address of environ: %p\n", (void*)environ);
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
