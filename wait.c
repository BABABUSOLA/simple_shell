#include "main_shell.h"


/**
 * main - prints all arguments it receives
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: Always 0(success)
 */

int main(int ac, char **av)

{
    (void)ac;
    int i = 0;

    while (av[i] != NULL)
    {
       printf("%s\n", av[i]);
       i++;
    }

     return (0);
}


