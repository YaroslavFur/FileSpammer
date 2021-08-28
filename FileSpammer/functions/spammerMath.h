#ifndef SPAMMERMATH_H
#define SPAMMERMATH_H

int rowsToMegabytes(int spamFiles, long long rows, int rowLenght);
long long megabytesToRows(int spamFiles, int megabytes, int rowLenght);
long long takeNumbersFromCharArray(char arr[], int endSymbol);
char* getSetOfRows(long long spamRows, char spamRow[], int* spamSets);

#endif /*SPAMMERMATH_H*/