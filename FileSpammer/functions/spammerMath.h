#ifndef SPAMMERMATH_H
#define SPAMMERMATH_H

int rowsToMegabytes(int spamFiles, int rows, int rowLenght);
int megabytesToRows(int spamFiles, int megabytes, int rowLenght);
long long takeNumbersFromCharArray(char arr[], int endSymbol);
char* getSetOfRows(int spamRows, char spamRow[], int* rowsInSet);

#endif /*SPAMMERMATH_H*/