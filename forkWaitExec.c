#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait &execute example
 *
 * Return: Always 0.
 */
int main(void)
{
	int number_of_children = 5;
	int i;
	pid_t child_pid;
	int status;

	for (i = 0; i < number_of_children; i++)
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
			char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

			printf("Before execve\n");
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			printf("After execve\n");
		}
		else
		{
			wait(&status);
			printf("Oh, it's all better now\n");
			if (WIFEXITED(status))
			{
				printf("Child process ID %d exited with status: %d\n", child_pid, WEXITSTATUS(status));
			}
			else
			{
			printf("Child process ID %d terminated abnormally\n", child_pid);
			}
		}
	}
	return (0);
}
