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
    one_count_t * a = NULL;
    int flag = 0;
    for(int i =0; i < c->len;i++)
      {
	a = c->arr[i];
	if(!strcmp(a->str,name)){
	  a->count ++;
	  flag = 1;
	  break;
	}
      }
    if(flag == 0){
      one_count_t *b = NULL;
      b = malloc(sizeof(*b));
      if(b==NULL)
	return;
      b->str = malloc(strlen(name)+8);
      if(b->str == NULL){
	free(b);
	return;
      }
      strcpy(b->str, name);
      b->count = 1;
      c->arr = realloc(c->arr,(c->len+1)*sizeof(*c->arr));
      if(c->arr == NULL){
	free(b->str);
	free(b);
	return;
      }
      c->arr[c->len] = b;
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
  for(int i = 0; i < c->len; i++){
    free(c->arr[i]->str);
    free(c->arr[i]);
    }
  free(c->arr);
  free(c);
}