#include "main_shell.h"

void executer(char **argv){
	char *cmd = NULL, *cmd_main = NULL;
	
	if (argv)
	{
		cmd = argv[0];/* get the command */

        /* generate the path to this command before passing it to execve */
		cmd_main = getPath(cmd);

        /* execute the actual command with execve */
		if (execve(cmd_main, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
