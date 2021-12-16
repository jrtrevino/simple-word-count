#ifndef FILEIO_H
#define FILEIO_H

flagConfig tryOpen(char *fileName, int bflag, int wflag, int lflag);
void readFile(FILE *fileName, unsigned int *words, unsigned int *newLine, unsigned int *bytes);
void openStdin(int cflag, int wflag, int lflag);
void sendForPrinting(flagConfig thisConfig, int l, int w, int c);
#endif
