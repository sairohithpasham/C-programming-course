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
  }
  else{
    one_count_t * x =NULL;
    int flag =0;
    for(size_t i = 0; i< c->len;i++){
      x = c->arr[i];
      if(! strcmp(x->str,name)){
	x->count ++;
	flag=1;
      }
    }
    if(flag == 0){
      one_count_t *x1 = NULL;
      x1 = malloc(sizeof(*x1));
      x1->str = malloc(strlen(name)+8);
      strcpy(x1->str, name);
      x1->count = 1;
      c->arr = realloc(c->arr,(c->len+1)*sizeof(*c->arr));
      c->arr[c->len] = x1;
      c->len ++;
    }
  }
  
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
  for(int i = 0; i <= c->len; i++){
    free(c->arr[i]->str);
    free(c->arr[i]);
    }
  free(c->arr);
  free(c);
}
