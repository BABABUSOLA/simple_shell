#include <stdio.h>
#include <stdlib.h>

/**
 * get_environ - returns the string array copy of our environ
 * @name: The name Used to maintain
 *          constant
 *Return:  Always 0
*/

extern char **environ;  // Declare the global variable

char *_getenv(const char *name)
{
    if (name == NULL)
        return NULL;

    int i = 0;
    while (environ[i] != NULL)
    {
        // Check if the variable name matches
        char *variable = environ[i];
        int j = 0;
        while (name[j] != '\0' && name[j] == variable[j])
            j++;

        if (name[j] == '\0' && variable[j] == '=')
        {
            // Found a match, return the value part
            return variable + j + 1;
        }

        i++;
    }

    // Variable not found
    return NULL;
}

int main()
{
    // Example usage
    char *path = _getenv("PATH");
    if (path != NULL)
        printf("PATH = %s\n", path);
    else
        printf("PATH not found\n");

    return 0;
}
