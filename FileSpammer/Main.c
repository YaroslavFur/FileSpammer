#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
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
	int spamFiles = SPAM_FILES, spamRows = megabytesToRows(SPAM_FILES, SPAM_MB, strlen(SPAM_ROW));	// num of files to create, num of rows in ONE file
	char spamRow[256] = SPAM_ROW;

	getInput(&spamFiles, &spamRows, spamRow);

	char* name = (char*)calloc(1 + ZERO_SYMBOL_LENGTH_1, sizeof(char));
	char* tmpName;

	int rowsInSet;
	double sizeOfOneFile = rowsToMegabytes(spamFiles, spamRows, strlen(spamRow)) / (double)spamFiles;
	if (sizeOfOneFile <= 0.01) // if size of one file <= 1 KB
	{
		rowsInSet = spamRows;
	}
	else if (sizeOfOneFile <= 1) // if size of one file <= 1 MB
	{
		rowsInSet = spamRows / 1000;
	}
	else // if size of one file >1 MB
	{
		rowsInSet = spamRows / 1000;
	}
	char* setOfRows = (char*)calloc((strlen(spamRow) + 1) * rowsInSet + ZERO_SYMBOL_LENGTH_1, sizeof(char));
	char* spamRowWithNewlineCharacter = (char*)calloc((strlen(spamRow) + 1) + ZERO_SYMBOL_LENGTH_1, sizeof(char));
	spamRowWithNewlineCharacter = strcat(spamRow, "\n");
	for (int i = 1; i < rowsInSet; i++) // create set of rows because it's much faster to fprintf set of rows that lots of rows by one
	{
		setOfRows = strcat(setOfRows, spamRowWithNewlineCharacter);
	}

	FILE* f;
	double percent = 0.0;
	
	printf("Please wait, spamming...\n\n");

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
		name = strcat(name, ".txt");

		if ((f = fopen(name, "w")) == NULL)
		{
			printMessageError("Smth wrong with creating file...");
			break;
		}

		for (int rowCount = 1; rowCount <= spamRows; rowCount += rowsInSet)
		{
			fprintf(f, "%s\n", setOfRows);
			while (((i - 1) * spamRows) + rowCount >= ceilMy(spamRows * spamFiles * percent)) // if current printed rows > all rows*percent,
			{
				printProgressBar(percent, 30, 0); // print progressBar with this percent
				percent += 0.01;
			}
		}
		fclose(f);

		

		if (i == spamFiles)
		{
			printProgressBar(1, 30, 0); // just to be sure :3
			printf("\n\n");
			printf("Spammed successfully\n"
				"Have a great day!\n");
		}
	}

	free(name);
	

	_getch();
	return 0;
}