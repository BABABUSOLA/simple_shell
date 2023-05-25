#include "main_shell.h"
/**
 * executer - function to run fork wait and execute
 * @argv: array of arguments
 * Return: Always 0.
 */

void executer(char **argv)
{
	char *cmd = NULL, *cmd_main = NULL;
	int i = 0;
	pid_t child_pid;
	int status;

	/*if (argv)*/
	/*{*/
		/*cmd = argv[0]; get the command */
	while (argv[i] != NULL)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: child pid");
		}
		if (child_pid == 0)
		{
			cmd = argv[i];
        /* generate the path b4 taking it to execve */
			cmd_main = getPath(cmd);

        /* execute the actual command with execve */
			if (execve(cmd_main, argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				exit(0);
			}

		}

	i++;
	}
	/*}*/
}
