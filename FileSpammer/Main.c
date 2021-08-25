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
#define SPAM_ROWS 1000000
#define SPAM_ROW "SPAM"

// here goes spamming process
int main()
{	
	int spamFiles = SPAM_FILES, spamRows = SPAM_ROWS;
	char spamRow[256] = SPAM_ROW;

	getInput(&spamFiles, &spamRows, spamRow);

	printf("Please wait, spamming...\n\n");

	char* name = (char*)calloc(1 + ZERO_SYMBOL_LENGTH_1, sizeof(char));
	char* tmpname;
	FILE* f;

	double percent = 0.0;
	printProgressBar(percent, 30, 0);

	for (int i = 1, count = 1; i <= spamFiles; i++)
	{
		if (myDigits(i) > count)
		{
			count++;
			tmpname = (char*)realloc(name, (count + DOTTXT_LENGTH_4 + ZERO_SYMBOL_LENGTH_1) * sizeof(char));
			if (tmpname == NULL)
			{
				printMessageError("Smth wrong with memory...");
				break;
			}
			name = tmpname;
		}
		itoa(i, name, 10);
		name = strcat(name, ".txt");

		if ((f = fopen(name, "w")) == NULL)
		{
			printMessageError("Smth wrong with creating file...");
			break;
		}

		for (int rowCount = 1; rowCount <= spamRows; rowCount++)
		{
			fprintf(f, "%s\n", spamRow);
		}
		fclose(f);

		while (i >= myCeil(spamFiles * percent))
		{
			printProgressBar(percent, 30, 0);
			percent += 0.01;
		}

		if (i == spamFiles)
		{
			printf("\n\n");
			printf("Spammed successfully\n"
				"Have a great day!\n");
		}
	}

	free(name);
	

	_getch();
	return 0;
}