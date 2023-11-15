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
  FILE * g;
  if(f == NULL)
    {
      fprintf(stderr,"File cant be opened\n");
      return EXIT_FAILURE;
    }
  int i=0;
  char arr[10][12];
  while(fgets(arr[i],12,f)!=NULL)
    {
      if(i<9)
	{
	  g = f;
	  int d;
	  while((d=fgetc(g))==EOF)
	    {
	      fprintf(stderr,"less than 10 lines entered 2");
	      return EXIT_FAILURE;
	    }
	}
      if(i>=10)
	{
	  fprintf(stderr,"The input has more than 10 lines\n");
	  return EXIT_FAILURE;
	}
      if(strchr(arr[i],'\n') == NULL)
	{
	  fprintf(stderr,"A line has more than 10 elements in it.\n");
	  return EXIT_FAILURE;
	}
      if(strlen(arr[i])<11)
	{
	  fprintf(stderr,"A line has less than 10 elements in it.\n");
	  return EXIT_FAILURE;
	}
      i++;
      if(i==10)
	{
	  int c;
	  while((c=fgetc(f))!=EOF)
	    {
	      fprintf(stderr,"more than 10 lines entered");
	      return EXIT_FAILURE;
	    }
	}
    }
  if(i<9)
    {
      fprintf(stderr,"Less than 10 lines entered\n");
      return EXIT_FAILURE;
    }
  
  rotate(arr);
  if(fclose(f)!=0)
    {
      fprintf(stderr,"file cant be closed\n");
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
