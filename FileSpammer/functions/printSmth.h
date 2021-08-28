#ifndef PRINTSMTH_H
#define PRINTSMTH_H

void printMessageError(char message[]);
void printSettings(int spamFiles, char spamRow[], int megabytes);
void printProgressBar(double percent, int steps, int newLineAfterBar);
void printTime(double timeInSecons);

#endif /*PRINTSMTH_H*/