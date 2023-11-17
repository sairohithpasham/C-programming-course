#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t * c = createCounts();
  FILE * f = fopen(filename, "r");
  if(f==NULL){
    fprintf(stderr,"Can't open the file");
    return NULL;
  }
  char * line = NULL;
  size_t sz = 0;
  while(getline(&line,&sz,f)>=0){
    char * a = strchr(line,'\n');
    if(a!=NULL){
      *a = '\0';
    }
    char * b = lookupValue(kvPairs, line);
    addCount(c,b);
  }
  free(line);
  if(fclose(f)!=0) return NULL;
  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc<2){
    fprintf(stderr,"atleast 2 cl arguments");
    return EXIT_FAILURE;
  }
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * k = readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)
  for(int  i = 2; i < argc; i++){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    counts_t *c = countFile(argv[i], k);
    if(c == NULL)
      return EXIT_FAILURE;
    //   (call this result c)
    
    //compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);

    //open the file named by outName (call that f)
    FILE * f1 = fopen(outName, "w");
    //print the counts from c into the FILE f
    printCounts(c,f1);
    //close f
    if(fclose(f1)!=0)
      return EXIT_FAILURE;
    //free the memory for outName and c
    free(outName);
    free(c);

  }
 //free the memory for kv

  return EXIT_SUCCESS;
}
