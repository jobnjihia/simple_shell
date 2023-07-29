#include "shell.h"

/**
 * inbuilts - search for match and execute the associate built-in
 * @data: struct for the program's data
 * Return: Returns the return of the function executed if they match,
 * else returns -1.
 */
int inbuilts(program_data *data)
{
	int j;
	inbuilt options[] = {
		{"help", inbuilt_help},
		{"cd", inbuilt_cd},
		{"exit", inbuilt_exit}
		{"alias", inbuilt_alias},
		{"env", inbuilt_env},
		{"setenv", inbuilt_set_env},
		{"unsetenv", inbuilt_unset_env},
		{NULL, NULL}
	};

	for (j = 0; options[j].inbuilt != NULL; j++)
	{
		if (str_compare(options[j].inbuilt, data->program_title, 0))
		{
			return (options[j].fctn(data));
		}
	}
	return (-1);
}
