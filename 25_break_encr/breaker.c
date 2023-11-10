#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void frequency(int * letterCount, FILE * f)
{
  int c;
  while(c = fgetc(f)!=EOF)
    {
      if(isalpha(c))
        {
          c = tolower(c);
          letterCount[c - 'a']++;
        }
    }
}

int main(int argc, char **argv)
{
  if(argc != 2)
    {
      fprintf(stderr,"enter exactly one command-line argument other than the name of the file");
      return EXIT_FAILURE;
    }
  FILE *file = fopen(argv[1],"r");
  if(file==NULL)
    {
      perror("cannot open the file");
      return EXIT_FAILURE;
    }
  int letterCount[26] = {0};
  frequency(letterCount, file);
  int max=0;
  for(int i = 1; i < 26; i++)
    {
      if(letterCount[i] > letterCount[max])
        {
          max = i;
        }
    }
  int key;
  if(max >= ('a' - 'e'))
    key = max - ('a' - 'e');
  else
    key = (26 - ('a' - 'e')) + max;
  printf("%d\n", key);

  if(fclose != 0)
    {
      perror("Failed to close the input file");
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
