#include<stdio.h>
#include<stdlib.h>
struct _retire_info{
  int months;
  double contribution, rate_of_return;
};
typedef struct _retire_info retire_info;

double bal(double balance, retire_info xyz)
{
  double ans;
  ans = balance + (balance * xyz.rate_of_return) + xyz.contribution;
  return ans;
}
void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  int month, year;
  double balance_working, balance,balance_retired;
  balance = initial;
  printf("Age %3d month %2d you have $%.2lf\n",startAge/12,startAge%12,balance);
  for(int i = startAge+1; i <= startAge + working.months; i++)
    {
      balance_working = bal(balance,working);
      balance = balance_working;
      year = i / 12;
      month = i % 12;
      printf("Age %3d month %2d you have $%.2lf\n",year,month,balance);
    }
  for(int j = startAge + working.months+1; j < startAge+working.months+retired.months; j++)
    {
      balance_retired = bal(balance, retired);
      balance = balance_retired;
      year = j/12;
      month = j%12;
      printf("Age %3d month %2d you have $%.2lf\n",year,month,balance);
    }
}
int main()
{
  retire_info working,retired;
  int startAge = 327;
  double savings = 21345;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = (0.045/12);

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = (0.01/12);

  
  retirement(startAge, savings, working, retired);
  return EXIT_SUCCESS;
}
