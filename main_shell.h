#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *string);
char **splitString(const char *string, int *wordCount);
char **strtow(char *str);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
int print_d(int input, int fd);
void _puts(char *str);
int _putchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/*converter.c */
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);

ssize_t my_getline(char **buff, size_t *length);

int executer(char **argv);
char *getPath(char *command);

/*error.c*/
void print_error(char *fname, int line_count, char **argv, char *estr);

#endif
