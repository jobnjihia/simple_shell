#include "shell.h"

/**
 * main - main entry point of the program
 * @ac: number of items
 * @av: null terminated array of strings
 * Return: 1
 */

int main(void)
{
	char *prompter = "#cisfun$ ";
	char *userInput = "";
	char **inputArray;
	char *str_copy1;
	char *str_copy2;
	pid_t childPid;
	int status;
	size_t n = 0;
	/*int commandResult = 0;*/
	char *delim = " ";
	char *token;
	char *token2;
	int numOfTokens = 0;
	int counter = 0;

	printf("%s ", prompter);

	while ((getline(&userInput, &n, stdin) != EOF))
	{
		str_copy1 = malloc((strlen(userInput) + 1) * sizeof(char));
		str_copy2 = malloc((strlen(userInput) + 1) + sizeof(char));

		strcpy(str_copy1, userInput);
		strcpy(str_copy2, userInput);

		/* Calculate number of tokens from the user input */
		token = strtok(str_copy1, delim);

		numOfTokens = 0;

		while (token != NULL)
		{
			numOfTokens++;
			token = strtok(NULL, delim);
		}

		/* memory allocation for array */

		inputArray = malloc(sizeof(char *) * numOfTokens);

		/* store token element in inputArray */
		token2 = strtok(str_copy2, delim);

		counter = 0;
		while (token2 != NULL)
		{
			inputArray[counter] = malloc(strlen(token2) * sizeof(char));
			strcpy(inputArray[counter], token2);

			/*printf("\n%s ", token2);*/
			counter++;
			token2 = strtok(NULL, delim);
		}

		if  (numOfTokens > 0)
		{
			childPid = fork();

			if  (childPid == -1)
			{
				perror("\nAn error occured creating a process\n");
			}
			else if (childPid == 0)
			{
				if (execve(inputArray[0], inputArray, NULL) == -1)
				{
					perror("Error: ");
				}
			}
			else
			{
				waitpid(childPid, &status, 0);
			}
		}

		printf("%s", prompter);
	}

	free(userInput);
	free(str_copy1);
	free(str_copy2);

	return (1);
}
