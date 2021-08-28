#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "simpleMath.h"
#include "printSmth.h"
#include "spammerMath.h"

#define MAX_DIGITS_IN_MB_VALUE 7

// allows user to enter data with dynamical transfer it to another value and showing to user with each key press update (12_ => 12_ is 24, 123_ => 123_ is 246)
int scanfMbAndRows(int maxDigits, char textInLineBeforeNumber[], int spamFiles)
{
	int ch, secondCh, megabytes;
	double megabytesInEachFile;
	char code[32];
	int current = 0, numOfDigits = 0, flagNeedToUpdate = 0;

	while (1)
	{
		ch = _getch();

		if ((ch >= 48 && ch <= 57) || ch == 8 || (ch == 0 || ch == 224))
			flagNeedToUpdate = 1;
		else
			flagNeedToUpdate = 0;

		if (ch >= 48 && ch <= 57) // 0-9
		{
			if (numOfDigits < maxDigits)
			{
				if (current < numOfDigits)
				{
					for (int i = numOfDigits; i > current; i--)
					{
						code[i] = code[i - 1];
					}
				}

				code[current] = ch;
				current++;
				numOfDigits++;
			}
		}
		if (ch == 8) // backspace
		{
			if (current > 0)
			{
				for (int i = current - 1; i < numOfDigits; i++)
				{
					code[i] = code[i + 1];
				}
				current--;
				numOfDigits--;
			}
		}
		if (ch == 0 || ch == 224) // left right up down delete
		{
			secondCh = _getch();
			if (secondCh == 83)	// delete
			{
				if (numOfDigits > 0 && current != numOfDigits)
				{
					numOfDigits--;
					for (int i = current; i < numOfDigits; i++)
					{
						code[i] = code[i + 1];
					}
				}
			}
			if (secondCh == 75)	// left
			{
				if (current > 0)
					current--;
			}
			if (secondCh == 77)	// right
			{
				if (current < numOfDigits)
					current++;
			}
			if (secondCh == 71)	// home
			{
				current = 0;
			}
			if (secondCh == 79)	// end
			{
				current = numOfDigits;
			}
		}
		if (ch == 13) // enter
		{
			if (code[0] >= 48 && code[0] <= 57) // if user has entered some number - finish
			{
				printf("\n");
				break;
			}
		}

		if (flagNeedToUpdate)
		{
			printf("\r");
			for (int i = 0; i < (strlen(textInLineBeforeNumber) + maxDigits * 2 + 60) / 10; i++)	// +50 just in case
			{
				printf("          ");
			}
			printf("\r%s", textInLineBeforeNumber);
			for (int i = 0; i < numOfDigits; i++)
			{
				printf("%c", code[i]);
			}

			megabytes = takeNumbersFromCharArray(code, numOfDigits - 1);
			megabytesInEachFile = megabytes / (double)spamFiles;

			for (int i = 0, j = digitsMy(megabytes); i < maxDigits - j; i++)
			{
				printf(" ");
			}
			printf(" MB = %0.1lf MB in each file", megabytesInEachFile);
			if (megabytesInEachFile >= 1000)
				printf(" (isn't it too many?)");
			printf("\r%s", textInLineBeforeNumber);
			for (int i = 0; i < current; i++)
			{
				printf("%c", code[i]);
			}
		}
	}

	return megabytes;
}

// gets user settings for program if user wants
void getInput(int* spamFiles, long long* spamRows, char spamRow[])
{
	printf("Auto settings:\n");
	printSettings(*spamFiles, spamRow, rowsToMegabytes(*spamFiles, *spamRows, strlen(spamRow)));
	printf("> Continue with auto settings? (y/n)\t");

	char decision = ' ';
	while (decision != 'y' && decision != 'n')
	{
		decision = _getch();
		if (decision == 'y')
		{
			printf("\nAuto selected\n\n");
		}
		if (decision == 'n')
		{
			printf("\nManual selected\n\n");
			printf("> Files:   ");
			scanf("%d", spamFiles);
			printf("> Content: ");
			scanf("\n%255[^\n]", spamRow);		// catch excessive enter and read spamRow up to 255 symbols or user press enter
			printf("> Memory:  ");
			int megabytes = scanfMbAndRows(MAX_DIGITS_IN_MB_VALUE, "> Memory:  ", *spamFiles);
			*spamRows = megabytesToRows(*spamFiles, megabytes, strlen(spamRow));
			printf("Manual settings:\n");
			printSettings(*spamFiles, spamRow, rowsToMegabytes(*spamFiles, *spamRows, strlen(spamRow)));
		}
	}
}