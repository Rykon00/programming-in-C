#include <stdio.h>

/* Variables and memory
   have a look at the variables in your previous programs, e.g. address_list.c

   TO DO 1: Use sizeof to determine how much memory different types require in memory.
   TO DO 2: Also consider arrays, structs, enums and unions.
   TO DO 3: Use & to determine the addresses of different variables in memory.
   TO DO 4: Can you see a difference of addresses for local and global variables?
   TO DO 5: How are variables sorted in memory (increasing or decreasing addresses)?
   TO DO 6: What about addresses of local variables in recursive functions (e.g. hanoi.c)?
   TO DO 7: Can you find int variables stored at uneven addresses? How do you judge the result?
   TO DO 8: What is the size of the following struct? Why? Can it be reduced?

struct test {
        char a;
        int b;
        char c;
        int d;
};
*/

struct test {
    char a;
    int b;
    char c;
    int d;
};

struct optimized_test {
    char a;
    char c;
    int b;
    int d;
};

char globalChar;
int globalInt;

void printSizes() {
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of int array[10]: %zu bytes\n", sizeof(int[10]));
    printf("Size of struct test: %zu bytes\n", sizeof(struct test));
    printf("Size of enum {A, B, C}: %zu bytes\n", sizeof(enum {A, B, C}));
    printf("Size of union {int x; float y;}: %zu bytes\n", sizeof(union {int x; float y; }));
}

void printAddresses() {
    char a;
    int b;
    float c;
    double d;
    int arr[10];
    struct test s;
    enum { A,
           B,
           C } e;
    union {
        int x;
        float y;
    } u;

    printf("Address of char a: %p\n", (void *)&a);
    printf("Address of int b: %p\n", (void *)&b);
    printf("Address of float c: %p\n", (void *)&c);
    printf("Address of double d: %p\n", (void *)&d);
    printf("Address of int array arr: %p\n", (void *)&arr);
    printf("Address of struct test s: %p\n", (void *)&s);
    printf("Address of enum e: %p\n", (void *)&e);
    printf("Address of union u: %p\n", (void *)&u);
}

void printGlobalLocalAddresses() {
    char localChar;
    int localInt;

    printf("Address of global char: %p\n", (void *)&globalChar);
    printf("Address of global int: %p\n", (void *)&globalInt);
    printf("Address of local char: %p\n", (void *)&localChar);
    printf("Address of local int: %p\n", (void *)&localInt);
}

void printVariableOrder() {
    char a;
    int b;
    float c;

    printf("Address of char a: %p\n", (void *)&a);
    printf("Address of int b: %p\n", (void *)&b);
    printf("Address of float c: %p\n", (void *)&c);
}

void recursiveFunction(int level) {
    int localVar = level;
    printf("Level %d, Address of localVar: %p\n", level, (void *)&localVar);
    if (level > 0) {
        recursiveFunction(level - 1);
    }
}

void checkIntAddressAlignment() {
    int a;
    printf("Address of int a: %p\n", (void *)&a);
    if ((uintptr_t)&a % sizeof(int) != 0) {
        printf("int a is stored at an uneven address!\n");
    } else {
        printf("int a is stored at an even address.\n");
    }
}

void printStructSizes() {
    printf("Size of struct test: %zu bytes\n", sizeof(struct test));
    printf("Size of struct optimized_test: %zu bytes\n", sizeof(struct optimized_test));
}

int main() {
    printSizes();
    printAddresses();
    printGlobalLocalAddresses();
    printVariableOrder();
    recursiveFunction(3);
    checkIntAddressAlignment();
    printStructSizes();
    return 0;
}