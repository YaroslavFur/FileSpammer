#define NEWLINE_CHARACTER_IN_TXTFILE_LENGTH_2 2

int rowsToMegabytes(int spamFiles, int rows, int rowLenght)
{
	double megabytes = rows + 1;													// +1 ��� ��������� �������� � �����
	megabytes *= spamFiles;															// ������� ������� � ��� �����
	megabytes *= rowLenght + NEWLINE_CHARACTER_IN_TXTFILE_LENGTH_2;					// ���������� � �����
	megabytes /= 1000000.0;															// ���������� � ���������

	return megabytes;
}

int megabytesToRows(int spamFiles, int megabytes, int rowLenght)
{
	double rows = megabytes;
	rows *= 1000000;																// ���������� � �����
	rows /= rowLenght + NEWLINE_CHARACTER_IN_TXTFILE_LENGTH_2;						// ���������� � �����
	rows /= spamFiles;																// �������� ����� �� ��� ������, � �������� �-��� � ������ ����

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