#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "initializer.h"
#include "fileio.h"

int checkPreviousChar(int prev)
{
   if (prev > 0)
      return 1;
   return 0;
}
int checkNewline(int c)
{
   if (c == '\n')
      return 1;
   else
      return 0;
}

int checkWord(int numLetters, int printable)
{
   /**if (numLetters >= 1 && printable >= 1**/
   if (printable >= 1)
      return 1;
   else
      return 0;
}

int checkLast(int last)
{
   if ((isprint(last)) == 0 && isspace(last) != 0)
      return 1;

   return 0;

}

void readFile(FILE *fileName, unsigned int *words, unsigned int *newLine,
   unsigned int *bytes)
{
   unsigned int c,last, numWords, numBytes, numLines, printable;
   numWords  = last =  numBytes = printable = numLines =0;
   while ((c = fgetc(fileName)) != EOF)
   {
      ++numBytes;
      if (isspace(c) == 0)
      {
         printable += isprint(c);
      }
      else
      {
         numLines += checkNewline(c);
         numWords += checkWord(0, printable);
         printable = 0;
      }
   }
   numWords += checkWord(0,printable);
   *words = numWords;
   *newLine = numLines;
   *bytes = numBytes;
}

void printer(unsigned int this, int *counter, int totalFlags)
{
   printf("%10u", this);
   if(*counter < totalFlags-1)
      printf(" ");
   *counter += 1;
}

void sendForPrinting(flagConfig thisConfig, int l,int w,int c)
{
   int totalFlag, counter = 0;
   if (l==0 && w==0 && c==0)
      l=w=c=1;
   totalFlag = l + w + c;
   if (c ==1)
      printer(thisConfig.l, &counter, totalFlag);
   if (w ==1)
      printer(thisConfig.w, &counter, totalFlag);
   if (l ==1)
      printer(thisConfig.c, &counter, totalFlag);
}

void openStdin(int cflag, int wflag, int lflag)
{
   flagConfig stdConfig;
   unsigned int w =0, l=0, c=0;

   readFile(stdin,&w,&l,&c);
   stdConfig = makeConfig(c,w,l,0);
   sendForPrinting(stdConfig,cflag,wflag,lflag);
   fclose(stdin);
   printf("\n");
}

flagConfig tryOpen(char *fileName,int cflag,int wflag, int lflag)
{
      
   FILE* current;
   flagConfig thisConfig;
   unsigned int w=0, l=0, c=0;
   current = fopen(fileName, "rb");
   if (current == NULL)
   {
      fprintf(stderr, "swc: ");
      perror(fileName);
      thisConfig = makeConfig(0,0,0,1);
   }
   else
   {
      readFile(current, &w, &l, &c);
      thisConfig = makeConfig(c,w,l,0);
      sendForPrinting(thisConfig,cflag,wflag,lflag);
      printf(" %s\n",fileName);
      fclose(current);
   }
   return thisConfig;
}
