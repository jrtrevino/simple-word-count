#ifndef INITIALIZER_H
#define INITIALIZER_H


typedef struct
{
   unsigned int bytes, words, count;
} fileCount; 

typedef struct
{
   int c, w, l;
   int cflag, wflag, lflag;
   int fileRead;
} flagConfig;

flagConfig makeConfig(int c, int w, int l, int read);

int checkFlags(char* arg, int *c, int *w, int *l);
flagConfig sendArgForPrinting(char* arg, int c, int w, int l, int *filesRead);
#endif
