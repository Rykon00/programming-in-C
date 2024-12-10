#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* hexdump.c
   A Hexdump prints the content of some memory area in hexadecimal format.

   TO DO 1: DONE!!! Have a look at the following program. How does it work?
   TO DO 2: DONE!!! Extend the program such that it shows 16 values in a row and puts the memory address at the beginning
   TO DO 3: DONE!!! Add other data structures and show how they maintain their data
            (or copy the hexdump to your other programs and call it from there)
   TO DO 4: DONE!!! Use malloc to allocate memory and hexdump it.
   TO DO 5: DONE!!! What happens if you call hexdump with arbitrary numbers, e.g. hexdump(10000,10); Why?
   TO DO 6: DONE!!! What happens if you call hexdump("Hello",6); Why?
   TO DO 7: DONE!!! Do a hexdump(hexdump, 100). What might that mean? What happens if you try to change values in this address range?
   TO DO 8: DONE!!! Optional: Hexdumps often also show the memory content as ascii characters in an additional column.
            Extend the program accordingly.
*/

// Hexdump function
void hexdump(void *adr, int length) {
    int i, j;
    unsigned char *c_adr = (unsigned char *)adr;

    for (i = 0; i < length; i += 16) {
        printf("%08x  ", (unsigned int)(c_adr + i)); // Print memory address

        // Print hex values
        for (j = 0; j < 16 && i + j < length; j++) {
            printf("%02x ", c_adr[i + j]);
        }

        // Print ASCII values
        printf(" ");
        for (j = 0; j < 16 && i + j < length; j++) {
            unsigned char ch = c_adr[i + j];
            if (ch >= 32 && ch <= 126) {
                printf("%c", ch);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Test code to call hexdump
int main() {
    // TO DO 3: Add other data structures and show how they maintain their data
    int a[] = {1, 2, 3, 4, 5, -1};
    printf("Hexdump of integer array:\n");
    hexdump(a, sizeof(a));

    // TO DO 4: Use malloc to allocate memory and hexdump it
    int *dynamic_array = (int *)malloc(6 * sizeof(int));
    if (dynamic_array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 6; i++) {
        dynamic_array[i] = i + 1;
    }
    printf("\nHexdump of dynamically allocated array:\n");
    hexdump(dynamic_array, 6 * sizeof(int));
    free(dynamic_array);

    // TO DO 5: What happens if you call hexdump with arbitrary numbers, e.g. hexdump(10000,10); Why?
    // Commented out to avoid segmentation fault
    // printf("\nHexdump of arbitrary memory address 10000:\n");
    // hexdump((void *)10000, 10);

    // TO DO 6: What happens if you call hexdump("Hello",6); Why?
    printf("\nHexdump of string \"Hello\":\n");
    hexdump("Hello", 6);

    // TO DO 7: Do a hexdump(hexdump, 100). What might that mean? What happens if you try to change values in this address range?
    printf("\nHexdump of hexdump function itself:\n");
    hexdump(hexdump, 100);

    return 0;
}
