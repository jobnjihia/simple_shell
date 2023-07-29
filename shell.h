#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

/*
 * struct - struct of shell data
 * @program_title: name of executable file
 * @cli_input: input ptr to read
 * @command_input pointer to the first command typed by the user
 * @input_counter: num of executable commands
 * @file_disc: desctiptor to command comman inputs
 * @tokens: ptr to array of tokenized userinput
 * @enviro: program environment
 * @steam: array of ptrs
 */
typedef struct necessary_info
{
	int *cli_input;
	char command_input;
	char input_counter;
	char file_disc;
	char **tokens;
	char **enviro;
	char **steam;
	char program_title;
}program_data;

/*
 * struct inbuilt - struct of builds
 * @inbuilt: name of the struct
 * @fctn: function applied toeach inbuilt
 */

typedef struct inbiult
{
	char *inbuilt;
	int(*fctn)(program_data *data);
}inbuilt;

int print_current_time(void);
int inbuilts(program_data *data);
int exec(program_data *data);
int main(int argc, char *argv[], char envp[]);
int search_path(program_data *data);
char *tokenize_input(int *token_sum, char *lineptr, const char *delim);
void perror (const char *__s);

#endif
