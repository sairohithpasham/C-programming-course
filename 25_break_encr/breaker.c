#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int frequency(FILE *file)
{
  int letterCount[26] = {0};
  int c;
  while(c = fgetc(file)!=EOF)
    {
      if(isalpha(c))
        {
          c = tolower(c);
          c -= 'a';
	  letterCount[c]++;
        }
    }
  int max=0,j=0;
  for(int i=0;i<26;i++)
    {
      if(letterCount[i] > max)
	{
	  max = letterCount[i];
	  j = i;
	}
    }
  int key = 0;
  if(j >= ('e'-'a'))
    key = j - ('e'-'a');
  else
    key = (25 - ('e' - 'a')) + j;
  return key;
}

int main(int argc, char** argv)
{
  if(argc != 2)
    {
      perror("enter one cl argument");
      fprintf(stderr,"enter exactly one command-line argument\n");
      return EXIT_FAILURE;
    }
  FILE *file = fopen(argv[1],"r");
  if(file==NULL)
    {
      fprintf(stderr,"cant open the file");
      perror("cannot open the file\n");
      return EXIT_FAILURE;
    }
  int k;
  k=frequency(file);
  printf("%d\n", k);
  fclose(file);
  return EXIT_SUCCESS;
}
