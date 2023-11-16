#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * split(char * str){
  char * res = strchr(str,'=');
  *res = '\0';
  res ++;
  char * res1 = strchr(res,'\n');
  if(res1 != NULL){
    *res1 = '\0';
  }
  kvpair_t* kvpair = malloc((size_t)sizeof(*kvpair));
  kvpair->key = str;
  kvpair->value = res;
  return kvpair;
}
kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname,"r");
  if(f==NULL){
    fprintf(stderr,"File cant be opened");
    return NULL;
  }
  size_t sz = 0;
  char * line = NULL;
  kvpair_t * current_pair = NULL;
  kvarray_t * kvarray = malloc((size_t)(sizeof(*kvarray)));
  kvarray->array = NULL;
  kvarray->len = 0;
  
  while(getline(&line, &sz, f)>=0){
    current_pair = split(line);
    kvarray->array = realloc(kvarray->array,(kvarray->len+1)*(sizeof(*kvarray->array)));
    kvarray->array[kvarray->len] = current_pair;
    kvarray->len ++;
    line = NULL;
  }
  free(line);
  if(fclose(f)!=0)
    return NULL;
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i = 0;i<pairs->len;i++)
    {
      free(pairs->array[i]->key);
      free(pairs->array[i]);
    }
  free(pairs->array);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  kvpair_t* current_pair;
  for(int i=0;i<pairs->len;i++)
    {
      current_pair = pairs->array[i];
      printf("key = '%s' value = '%s'\n",current_pair->key,current_pair->value);
    }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  kvpair_t* curr_pair;
  for(int i=0;i<pairs->len;i++)
    {
      curr_pair=pairs->array[i];
      if(!(strcmp(curr_pair->key,key))){
	return curr_pair->value;
      }
    }
  return NULL;
}
