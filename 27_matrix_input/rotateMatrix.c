#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void rotate(char a[10][12])
{
  int i,j,temp;
  for(i = 0;i<10;i++)
    {
      for(j=i;j<10;j++)
	{
	  temp = a[i][j];
	  a[i][j] = a[j][i];
	  a[j][i] = temp;
	}
    }
  for(i=0;i<10;i++)
    {
      for(j=0;j<5;j++)
	{
	  temp = a[i][j];
	  a[i][j] = a[i][9-j];
	  a[i][9-j] = temp;
	}
    }
  for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
	{
	  printf("%c",a[i][j]);
	}
      printf("\n");
    }
}

int main(int argc, char **argv)
{
  if(argc != 2)
    {
      fprintf(stderr,"Enter only one cl argument\n");
      return EXIT_FAILURE;
    }
  FILE * f = fopen(argv[1],"r");
  if(f == NULL)
    {
      fprintf(stderr,"File cant be opened\n");
    }
  int i=0;
  char arr[10][12];
  while(fgets(arr[i],12,f)!=NULL)
    {
      if(strchr(arr[i],'\n') == NULL)
	{
	  fprintf(stderr,"A line has more than 10 elements in it.");
	  return EXIT_FAILURE;
	}
      i++;
    }
  rotate(arr);
  fclose(f);
  return EXIT_SUCCESS;
}
