/* power.c */
#include <stdio.h>

int power(int x, int n)  
{
   int i, p;
   p = 1;
   for(i = 1; i <= n; i=i+1)
      p=p*x;
   return p;
}

int main()
{
   int i;
   for(i = 0; i <= 10; i = i+1)
      printf("%d %d %d\n", i, power(2,i), power(-3,i));
} 

