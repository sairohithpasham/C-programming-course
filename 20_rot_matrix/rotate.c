#include<stdio.h>
#include<stdlib.h>

void rotate(char matrix[10][10])
{
  int i,j,temp;
  for(i = 0; i<10; i++)
    {
      for(j = i; j < 10; j++)
	{
	  temp = matrix[i][j];
	  matrix[i][j] = matrix[j][i];
	  matrix[j][i] = temp;
	}
    }
  for(i = 0; i < 10; i++)
    {
      for(j = 0; j < 5; j++)
	{
	  temp = matrix[i][j];
	  matrix[i][j] = matrix[i][9-j];
	  matrix[i][9-j] = temp;
	}
    }
}
