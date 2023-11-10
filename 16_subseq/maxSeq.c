#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int *array, size_t n)
{
  int count, max_count = 1;
  if(n==0)
    return 0;
  count = 1;
  for(int i=1; i < n; i++)
    {
      if(array[i-1]<array[i])
	{
	  count++;
	  
	}
      else
	{
		count = 1;
	}
	  if(max_count < count)
	    {
	      max_count = count;
	    }
	
    }
  return max_count;
}
