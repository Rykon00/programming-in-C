/* hexdump.c
   A Hexdump prints the content of some memory area in hexadecimal format.

   TO DO 1: Have a look at the following program. How does it work?
   TO DO 2: Extend the program such that it shows 16 values in a row and puts the memory address at the beginning
   TO DO 3: Add other data structures and show how they maintain their data 
            (or copy the hexdump to your other programs and call it from there)
   TO DO 4: Use malloc to allocate memory and hexdump it.
   TO DO 5: What happens if you call hexdump with arbitrary numbers, e.g. hexdump(10000,10); Why?
   TO DO 6: What happens if you call hexdump("Hello",6); Why?
   TO DO 7: Do a hexdump(hexdump, 100). What might that mean? What happens if you try to change values in this address range?
   TO DO 8: Optional: Hexdumps often also show the memory content as ascii characters in an additional column.
            Extend the program accordingly.
 
*/

#include <math.h>
#include <stdio.h>

// Hexdump function 
void hexdump(void *adr, int length)
{
   int i;
   unsigned char *c_adr;

   for(i=0; i<length; i++) {
      printf("%2x ", *(unsigned char *)adr);
	 
      // Increment using char pointer (i.e. byte increments)
      c_adr=(unsigned char *)adr;      
      c_adr++;
      adr=(void *)c_adr;
   }
   printf("\n");
}

// Test code to call hexdump
int main()
{
   int a[]={ 1, 2, 3, 4, 5, -1  };

   hexdump(a,sizeof(a));
   getchar();
}
