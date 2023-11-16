#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char *outfile = malloc(strlen(inputName)*sizeof(outfile + 7*sizeof(outfile)));
  strcpy(outfile, inputName);
  outfile = strcat(outfile,".counts");
  return outfile;	
}
