#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "initializer.h"
#include "fileio.h"

void exitFunction(int exitCode)
{
   if (exitCode > 0)
      exit(1);
}

void checkArgs(int numArgs, char* argv[])
{
   flagConfig total;
   int totalc = 0, totalw=0,totall=0, exitCode = 0;
   int counter = 0, cflag = 0, wflag = 0, lflag = 0, argsRead = 0;
   int filesRead = 0;

   for (counter = 1; counter < numArgs; counter++)
   {
      argsRead += checkFlags(argv[counter],&cflag,&wflag,&lflag);         
   }
   
   for (counter = 1; counter < numArgs; counter++)
   {
      total = sendArgForPrinting(argv[counter],cflag,wflag,lflag,&filesRead);
      totalc += total.c;
      totalw += total.w;
      totall += total.l;
      exitCode += total.fileRead;
   }

   total.c = totalc;
   total.w = totalw;
   total.l = totall;
   
   if (argsRead == numArgs - 1)
      openStdin(cflag,wflag,lflag);     
   if (filesRead > 1)
   {
      sendForPrinting(total, cflag, wflag, lflag); 
      printf(" total\n"); 
   }
   exitFunction(exitCode);
}

int main(int numArgs, char* argv[])
{
   /**unsigned int c = 0,w = 0,l = 0;**/
   if (numArgs != 1)
      checkArgs(numArgs, argv);
   else
   {
      openStdin(0,0,0);
   }
   return 0;
}
