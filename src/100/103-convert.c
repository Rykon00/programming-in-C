/* Celsius - Fahrenheit converter */
#include <stdio.h>

int main( ) 
{
   int lower, upper, step;
   float cel, fahr;
   lower=0; upper=100; step=10;

   for(cel=lower; cel<=upper; cel=cel+step)
   {
      fahr=9.0/5.0*cel+32.0;
      printf("%5.1f  %5.1f\n",cel,fahr);  /* output */
   }
}