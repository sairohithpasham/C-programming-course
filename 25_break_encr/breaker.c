#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int frequency(FILE * file)
{
  int letterCount[26] = {0};
  int c;
  while(c = fgetc(file)!=EOF)
    {
      if(isalpha(c))
        {
          c = tolower(c);
          letterCount[c - 'a']++;
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
    key = (26 - ('e' - 'a')) + j;
  return key;
}

int main(int argc, char **argv)
{
  if(argc != 2)
    {
      fprintf(stderr,"enter exactly one command-line argument.");
      return EXIT_FAILURE;
    }
  FILE *file = fopen(argv[1],"r");
  if(file==NULL)
    {
      perror("cannot open the file");
      return EXIT_FAILURE;
    }
  int k;
  k=frequency(file);
  printf("%d\n", k);

  if(fclose != 0)
    {
      perror("Failed to close the input file");
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
