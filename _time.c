#include <stdio.h>
#include "time.h"

/**
 * print_current_time - entry point
 *
 * Return: 0 on success
 */
int main2(void)
{
	struct tm *localTime;
	char timeString[50];
	long currentTime;

	currentTime = time(NULL);

	localTime = localtime(&currentTime);
	strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
	printf("Current time: %s\n", timeString);

	return (0);
}
