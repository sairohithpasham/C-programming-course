#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * c = malloc(sizeof(*c));
  c->arr = NULL;
  c->len = 0;
  c->len_unknown = 0;
  return c;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name == NULL){
    c->len_unknown ++;
    return;
  }
  else{
    int len = c->len;
    char *entry = strdup(name);
    c->arr = realloc(c->arr, (c->len+1)*sizeof(* c->arr));
    for(int i=0; i<c->len;i++)
      {
	if(strcmp(c->arr[i]->str,name) == 0){
	  c->arr[i] -> count++;
	  free(entry);
	  return;
	}
      }
    c->arr[len] = malloc(sizeof(*c->arr[len]));
    c->arr[len]->str = entry;
    c->arr[len]->count = 1;
    c->len++;
  }
  return;
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(int i =0; i<c->len;i++){
    fprintf(outFile,"%s: %zd\n",c->arr[i]->str,c->arr[i]->count);
  }
  if(c->len_unknown!=0){
    fprintf(outFile,"<unknown> : %zd\n",c->len_unknown);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(int i = 0; i < c->len; i++){
    free(c->arr[i]->str);
    free(c->arr[i]);
    }
  free(c->arr);
  free(c);
}
