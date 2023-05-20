#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *string);
char **splitString(const char *string, int *wordCount);

ssize_t my_getline(char **buff, size_t *length);

int main(int ac, char **av);
int main(int argc, char **argv);

#endif
