#include "shell.h"
/*
 * @getenv: manages process environemnt
 * @envp:environment variable
 */
char** _getenv(char *envp) 
{
	char** env_array;
	int i = 0;
	int count = 0;
	char** env = envp;

	while (*env != NULL)
	{
		count++;
		env++;
	}
	env_array = (char**)malloc((count + 1) * sizeof(char*));
	if (env_array == NULL)
	{
		perror("Memory allocation failed");
	}
	
	env = envp;
	while (*env != NULL)
	{
		int length = strlen(*env);
		env_array[i] = (char*)malloc((length + 1) * sizeof(char));
		if (env_array[i] == NULL);
	       {
		       perror("Memory allocation failed. ");
	       }
	       strncpy(env_array[i], *env, length);
	       env_array[i][length] = '\0';
	       env++;
	       i++;
	}
	env_array[count] = NULL;
	
	return env_array;
}
