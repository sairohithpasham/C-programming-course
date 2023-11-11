#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int key(FILE *f){  
  int letters[26]={0};
  int c;
  
  while((c=fgetc(f)) != EOF){
     if (isalpha(c)) {
       c=tolower(c);
       c -= 'a';
       letters[c]++;
     }
  }
    int max=0;
    int j=0;
     for (int i=0 ;i<26; i++){
       if(letters[i] > max){
	 max=letters[i];
	 j=i;}
     }
     int key =  0;
     if (j >= ('e' - 'a')) key=j-('e'-'a') ;
     else key=(26-('e'-'a'))+ j; 
     return key ;
   }
  

  

  
int main(int argc,char** argv){
     if (argc != 2 ){
       fprintf(stderr,"Enter exactly one cl argument\n");
       return EXIT_FAILURE;
     }
    
    FILE * f= fopen(argv[1] ,"r");

    if (f == NULL) {
       perror("Cant open file");
       return EXIT_FAILURE;      
    }
    
    int k= key(f);
    printf("%d\n",k);
    
    if (fclose(f) != 0) {
       perror("Couldn't close the input file!");
       return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
    
 }
