#include "main_shell.h"

/**
 * *getPath - stat example
 * @cmd: array of arguments
 * Return: Always 0.
 */
char *getPath(char *cmd)
{
	char *path, *duplicate_path, *token, *file_path;
	int len_cmd, len_dir;
	struct stat st;

	path = getenv("PATH");
	if (path)
	{
		/* Duplicate the path string and free up memory*/ 
		duplicate_path = strdup(path);
		
		/* Get length of the command that was passed */
		len_cmd = strlen(cmd);
		/*break down the path variable, getthe directories available*/
		token = strtok(duplicate_path, ":");
		while (token != NULL)
		{
			/* Get the length of the directory*/
			len_dir = strlen(token);
			/* allocate memory for storing len_cmd and len_dir */
			file_path = malloc(len_cmd + len_dir + 2); /* NB: we added 2 for the slash and null character we will introduce in the full command */
           		 /* to build the path for the command, copy the file_path and concatenate the command */
			strcpy(file_path, token);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");

			/* test for file path existenc and return it true, else check next directory */
			if (stat(file_path, &st) == 0)
			{
				/* return value of 0 means success i.e file_path is valid*/
				/* free up allocated memory before returning your file_path */
				free(duplicate_path);
				return (file_path);
			}
			/* free up the file_path memory so we can check for another path*/
			free(file_path);
			token = strtok(NULL, ":");
		}
		/* if we don't get any file_path that exists for the command, we return NULL but we need to free up memory for path_copy */ 
		free(duplicate_path);
		/* before we exit without luck, let's see if the command itself is a file_path that exists */
		if (stat(cmd, &st) == 0)
		{
			return (cmd);
		}

        return (NULL);
    
    }


    return (NULL);
}
