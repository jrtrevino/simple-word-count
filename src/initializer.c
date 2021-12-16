#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "initializer.h"
#include "fileio.h"

flagConfig makeConfig(int c, int w, int l, int read)
{
   flagConfig newConfig;

   newConfig.c = c;
   newConfig.w = w;
   newConfig.l = l;
   newConfig.cflag = 0;
   newConfig.wflag = 0;
   newConfig.lflag = 0;
   newConfig.fileRead = read;
   return newConfig;

}
void badArguments(char* badArg)
{
   fprintf(stderr, "swc: invalid option: '%s'\n", badArg);
   fprintf(stderr, "Usage: swc [-l|-w|-c]... [file]...\n");
   exit(EXIT_FAILURE);
}

int checkFlags(char* arg, int *c, int *w, int *l)
{
   int matched=0;
   char cf[3] = "-c", wf[3] = "-w", lf[3] = "-l", df[2] = "-";
   if (strcmp(arg,cf) == 0)
      *c = matched = 1;
   if (strcmp(arg,wf) == 0)
      *w = matched = 1;
   if (strcmp(arg,lf) == 0)
      *l = matched = 1;
   if ((strncmp(arg,df,1)) == 0 && (matched != 1)) 
      badArguments(arg);
   return matched;
}
flagConfig sendArgForPrinting(char* arg, int c, int w, int l, int *filesRead)
{
   flagConfig current;
   char dash[2] = "-";
   if (c == 0 && w ==0 && l ==0)
      c =1, w = 1, l = 1;
   current = makeConfig(0,0,0,0);  
   if ((strncmp(arg,dash,1)) != 0)
   {
      current = tryOpen(arg,c,w,l);
      *filesRead += 1;
   }
   return current;
}
