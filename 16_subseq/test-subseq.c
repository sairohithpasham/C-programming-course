#include<stdio.h>
#include<stdlib.h>
#include "maxSeq.c"

int main()
{
  size_t  res;
  int array[] = {5,1,2,3,1,2,1};
  res = maxSeq(array, 7);
  if(res != 3)
    return EXIT_FAILURE;

  int array1[] = {};
  res = maxSeq(array1, 0);
  if(res != 0)
    return EXIT_FAILURE;

  int array2[] = {1,2,3,4};
  res = maxSeq(array2, 4);
  if(res != 4)
    return EXIT_FAILURE;

  int array3[] = {1,2,2,4};
  res = maxSeq(array3,4);
  if(res != 2)
    return EXIT_FAILURE;

  int array4[] = {1,-2,5,8};
  res = maxSeq(array4,4);
  if(res != 3)
    return EXIT_FAILURE;
  
  int array5[] = {7,6,5,4};
  res = maxSeq(array5,4);
  if(res != 1)
    return EXIT_FAILURE;
  
  int array6[] = {1,2,1,3,5,7,2,4,6,9};
  res = maxSeq(array6,10);
  if(res != 4)
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
