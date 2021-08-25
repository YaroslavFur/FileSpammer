#include <stdio.h>
#include "simplemath.h"

void printMessageError(char message[])
{
	printf("\n\n%s\n"
		"Better call Yarik\n"
		"yaroslav.fur.w3@gmail.com\n", message);
}

void printSettings(int spamFiles, char spamRow[], int megabytes)
{
	printf("\nFiles = %d\nRow = \"%s\"\nMegabytes = %d\n\n", spamFiles, spamRow, megabytes);
}

void printProgressBar(double percent, int steps, int newLineAfterBar)
{
	int step = myRound(percent * steps);
	if (!newLineAfterBar)
		printf("\r");
	printf("[");
	for (int i = 1; i <= steps; i++)
	{
		if (i <= step)
			printf("=");
		else
			printf(" ");
	}
	printf("] %d%%", myRound(percent * 100));
	if (newLineAfterBar)
		printf("\n");
}