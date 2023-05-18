#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>

int main(int ac, char **av);
int main(int argc, char **argv);
ssize_t my_getline(char **buff, size_t *length);
#endif
