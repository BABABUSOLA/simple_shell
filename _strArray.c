#include <stdio.h>
#include "main_shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * *_strdup - copies the content of input string to a new allocated memory
 * @string: string to be copied
 *
 * Return: the dynamically allocated duplicate
 */
char *_strdup(const char *string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}

	char *newString = malloc((length + 1) * sizeof(char));

	if (newString != NULL)
	{
		_strcpy(newString, string);
	}
	return (newString);

}

/**
 * *_strchr - locates a character in a string
 * @s: string to search
 * @c: char to find
 *
 * Return: a pointer to the first occurrence of the character
 * c in the string s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int a;

	while (1)
	{
		a = *s++;
		if (a == c)
		{
			return (s - 1);
		}
		if (a == 0)
		{
			return (NULL);
		}
	}
}

/**
 * **splitString - prints n elements of an array of words
 * followed by a new line
 * @string: input string
 * @wordCount: a pointer to an int variable stores the no of words found *
 * Return: token to corresponding element of the array
 */

char **splitString(const char *string, int *wordCount)
{
	const char *delim = " ";
	char *duplicate  = _strdup(string);
	int count = 0;

	char *token = strtok(duplicate, delim);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}

	char **words = malloc(count * sizeof(char));

	if (!words)
	{
		free(duplicate);
		return (NULL);
	}

	token = strtok(_strdup(string), delim);
	for (int i = 0; i < count; i++)
	{
		words[i] = _strdup(token);
		token = strtok(NULL, delim);
	}

	free(duplicate);
	*wordCount = count;
	return (words);
}
