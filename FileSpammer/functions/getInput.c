#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "printSmth.h"
#include "spammerMath.h"

#define MAX_DIGITS_IN_MB_VALUE 7

int scanfMbAndRows(int maxDigits, char textInLineBeforeNumber[], int spamFiles, char spamRow[])
{
	int ch, secondCh, megabytes, rows;
	char code[32];
	int current = 0, digits = 0;

	while (1)
	{
		ch = _getch();

		if (ch >= 48 && ch <= 57) // 0-9
		{
			if (digits < maxDigits)
			{
				if (current < digits)
				{
					for (int i = digits; i > current; i--)
					{
						code[i] = code[i - 1];
					}
				}

				code[current] = ch;
				current++;
				digits++;
			}
		}
		if (ch == 8) // backspace
		{
			if (current > 0)
			{
				for (int i = current - 1; i < digits; i++)
				{
					code[i] = code[i + 1];
				}
				current--;
				digits--;
			}
		}
		if (ch == 0 || ch == 224) // left right up down delete
		{
			secondCh = _getch();
			if (secondCh == 83)	// delete
			{
				if (digits > 0 && current != digits)
				{
					digits--;
					for (int i = current; i < digits; i++)
					{
						code[i] = code[i + 1];
					}
				}
			}
			if (secondCh == 75)	// left
				if (current > 0)
					current--;
			if (secondCh == 77)	// right
				if (current < digits)
					current++;
		}
		if (ch == 13)
		{
			printf("\n");
			break;
		}
		
		printf("\r");
		for (int i = 0; i < (strlen(textInLineBeforeNumber) + maxDigits * 3 + 30) / 2; i++)	// +50 про всяк випадок
		{
			printf("  ");
		}
		printf("\r%s", textInLineBeforeNumber);
		for (int i = 0; i < digits; i++)
		{
			printf("%c", code[i]);
		}
		
		megabytes = takeNumbersFromCharArray(code, digits - 1);
		rows = megabytesToRows(spamFiles, megabytes, strlen(spamRow)) * spamFiles;

		printf(" MB = %lld Rows in all files\r%s", rows, textInLineBeforeNumber);
		for (int i = 0; i < current; i++)
		{
			printf("%c", code[i]);
		}
	}

	return megabytes;
}


void getInput(int* spamFiles, int* spamRows, char spamRow[])
{
	printf("Auto settings:\n");
	printSettings(*spamFiles, spamRow, rowsToMegabytes(*spamFiles, *spamRows, strlen(spamRow)));
	printf("> Continue with auto settings? (y/n)\t");
	if (_getch() == 'y')
	{
		printf("\nAuto selected\n");
	}
	else
	{
		printf("\nManual selected\n"
			"> Files:  ");
		scanf("%d", spamFiles);
		printf("> Row:    ");
		scanf("%s", spamRow);
		printf("> Memory: ");
		int megabytes = scanfMbAndRows(MAX_DIGITS_IN_MB_VALUE, "> Memory: ", *spamFiles, spamRow);
		*spamRows = megabytesToRows(*spamFiles, megabytes, strlen(spamRow));

		printf("Manual settings:\n");
		printSettings(*spamFiles, spamRow, rowsToMegabytes(*spamFiles, *spamRows, strlen(spamRow)));
		getchar();									// ловить лишній ентер
	}
}