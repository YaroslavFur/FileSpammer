#define NEWLINE_CHARACTER_IN_TXTFILE_LENGTH_2 2

int rowsToMegabytes(int spamFiles, int rows, int rowLenght)
{
	double megabytes = rows + 1;													// +1 ùîá àíóëşâàòè ïğîáëåìè ç ³íòîì
	megabytes *= spamFiles;															// â³çüìåìî ğÿäî÷êè ç³ âñ³õ ôàéë³â
	megabytes *= rowLenght + NEWLINE_CHARACTER_IN_TXTFILE_LENGTH_2;					// ïåğåâåäåìî â áàéòè
	megabytes /= 1000000.0;															// ïåğåâåäåìî â ìåãàáàéòè

	return megabytes;
}

int megabytesToRows(int spamFiles, int megabytes, int rowLenght)
{
	double rows = megabytes;
	rows *= 1000000;																// ïåğåâåäåìî â áàéòè
	rows /= rowLenght + NEWLINE_CHARACTER_IN_TXTFILE_LENGTH_2;						// ïåğåâåäåìî â ğÿäêè
	rows /= spamFiles;																// ğîçä³ëèìî ğÿäêè ïî âñ³õ ôàéëàõ, ³ îòğèìàºìî ê-ñòü â îäíîìó ôàéë³

	return (int)rows;
}

long long takeNumbersFromCharArray(char arr[], int endSymbol)
{
	long long output = 0, megabytes, rows;
	for (long long i = endSymbol, j = 1; i >= 0; i--, j *= 10)
	{
		output += (arr[i] - 48) * j;
	}
	return output;
}