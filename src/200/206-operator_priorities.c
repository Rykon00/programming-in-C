/* operator priorities.c - investigate operator priorities */
/*
   TO DO 1: Think about the expressions: What will be the output of the programm?
            ...only then remove the last line und compile/run the program. Were your predictions correct?
   TO DO 2: With your neighbour: Exchange difficult expressions with each other
            - can you solve them without running the program?
            - use brackets to structure the expressions without changing their values
*/
// don 't-compile-this yet - read TO DO' s first.

#include <stdio.h>
// don 't-compile-this yet - read TO DO' s first.
int main() {
    // don 't-compile-this yet - read TO DO' s first.
    int a, b, c, d;
    int result;
    // don 't-compile-this yet - read TO DO' s first.
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    // don 't-compile-this yet - read TO DO' s first.
    result = a - b - c;
    // printf("result is %d\n", result);

    result = a << b << c;
    // printf("result is %d\n", result);

    result = d / b / b;
    // printf("result is %d\n", result);

    result = a > b ? b > c ? a : b : c;
    // printf("result is %d\n", result);

    // don 't-compile-this yet - read TO DO' s first.
}