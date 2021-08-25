#define NEWLINE_CHARACTER_IN_TXTFILE_LENGTH_2 2

// transfers rows from each file to Megabytes of all files
int rowsToMegabytes(int spamFiles, int rows, int rowLenght)
{
	double megabytes = rows + 1;													// +1 to cancel problems with int
	megabytes *= spamFiles;															// take rows from all files
	megabytes *= rowLenght + NEWLINE_CHARACTER_IN_TXTFILE_LENGTH_2;					// transfet to bytes
	megabytes /= 1000000.0;															// transfer to Megabytes

	return megabytes;
}

// transfers Megabytes of all files to rows in each file
int megabytesToRows(int spamFiles, int megabytes, int rowLenght)
{
	double rows = megabytes;
	rows *= 1000000;																// transfer to bytes
	rows /= rowLenght + NEWLINE_CHARACTER_IN_TXTFILE_LENGTH_2;						// transfer to Rows
	rows /= spamFiles;																// divide rows by all files, so get quantity in one file

	return (int)rows;
}

// returns number from array of chars, where one char is one digit (char arr[] = {'1', '7', '3'} => int output = 173)
long long takeNumbersFromCharArray(char arr[], int endSymbol)
{
	long long output = 0, megabytes, rows;
	for (long long i = endSymbol, j = 1; i >= 0; i--, j *= 10)
	{
		output += (arr[i] - 48) * j;
	}
	return output;
}