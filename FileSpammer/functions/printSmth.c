#include <stdio.h>
#include "simplemath.h"

// prints special message about error
void printMessageError(char message[])
{
	printf("\n\n%s\n"
		"Better call Yarik\n"
		"yaroslav.fur.w3@gmail.com\n", message);
}

// prints settings of spammer to be run
void printSettings(int spamFiles, char spamRow[], int megabytes)
{
	printf("\nFiles =   %d\nContent = %s\nMemory =  %d MB\n\n", 
			spamFiles, spamRow, megabytes);
}

// prints progress bar with percentage with selected settings ([======    ] 60%)
void printProgressBar(double percent, int steps, int newLineAfterBar)
{
	int step = roundMy(percent * steps);
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
	printf("] %d%%", roundMy(percent * 100));
	if (newLineAfterBar)
		printf("\n");
}