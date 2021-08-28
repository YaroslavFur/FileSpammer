#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions/printSmth.h"
#include "functions/simpleMath.h"
#include "functions/spammerMath.h"
#include "functions/getInput.h"

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#define DOTTXT_LENGTH_4 4
#define ZERO_SYMBOL_LENGTH_1 1

#define SPAM_FILES 100
#define SPAM_MB 500
#define SPAM_ROW "SPAM"

// here goes spamming process
int main()
{	
	int spamFiles = SPAM_FILES;
	long long spamRows = megabytesToRows(SPAM_FILES, SPAM_MB, strlen(SPAM_ROW));	// num of files to create, num of rows in ONE file
	char spamRow[256] = SPAM_ROW;
	clock_t time;

	getInput(&spamFiles, &spamRows, spamRow);

	time = clock();

	printf("Initialization...");
	char* name = (char*)calloc(1 + ZERO_SYMBOL_LENGTH_1, sizeof(char));
	char* tmpName;
	FILE* f;
	double percent = 0.0;
	
	int spamSets;
	char* setOfRows = getSetOfRows(spamRows, spamRow, &spamSets);
		
	printf("\rPlease wait, spamming...\n\n");

	printProgressBar(percent, 30, 0);

	for (int i = 1, count = 1; i <= spamFiles; i++)
	{
		if (digitsMy(i) > count)
		{
			count++;
			tmpName = (char*)realloc(name, (count + DOTTXT_LENGTH_4 + ZERO_SYMBOL_LENGTH_1) * sizeof(char));
			if (tmpName == NULL)
			{
				printMessageError("Smth wrong with memory...");
				break;
			}
			name = tmpName;
		}
		itoa(i, name, 10);
		strcat(name, ".txt");

		if ((f = fopen(name, "w")) == NULL)
		{
			printMessageError("Smth wrong with creating file...");
			break;
		}

		for (int setCount = 1; setCount <= spamSets; setCount += 1)
		{
			fprintf(f, "%s", setOfRows);
			while ((((long long)(i - 1)) * spamSets) + setCount >= ceilMy(spamSets * spamFiles * percent)) // if current printed sets > all sets*percent,
			{
				printProgressBar(percent, 30, 0); // print progressBar with this percent
				percent += 0.01;
			}
		}
		fclose(f);

		if (i == spamFiles)
		{
			printProgressBar(1, 30, 0); // just to be sure :3

			time = clock() - time;
			double timeTaken = ((double)time) / (double)CLOCKS_PER_SEC;

			printf("\n\n");
			printf("Spammed successfully\n"
					"Time taken: ");
			printTime(timeTaken);
			printf("Have a great day!\n", timeTaken);
		}
	}

	free(name);
	free(setOfRows);
	
	_getch();
	return 0;
}