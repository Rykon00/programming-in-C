/* prime sieve of Eratosthenes */

#include <stdio.h>

#define Max 100

int main()
{
   int i, j;
   unsigned char is_prime[Max]; 

   /* Initialize Array */
   for(i=0; i<Max; i=i+1) 
      is_prime[i]=1;
	
   for (i=2; i<Max; i=i+1)  
      for (j= 2*i; j <Max; j=j+i)
        is_prime[j] = 0;

   printf("Prime numbers are: ");
   for(i=2; i<Max; i=i+1)
      if(is_prime[i]>0)
         printf("%d ",i);  
}