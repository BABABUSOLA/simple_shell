#include "main_shell"


int main()
{
	const char* str = "Hello world! Welcome to the programming world.";
	int wordCount;
	char** words = splitString(str, &wordCount);
	
	if (words != NULL)
	{
		printf("Number of words: %d\n", wordCount);
		for (int i = 0; i < wordCount; i++) {
			printf("Word %d: %s\n", i + 1, words[i]);
			free(words[i]);
		}
		free(words);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}
