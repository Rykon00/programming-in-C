// Ackermann: calculate the Ackermann function
// The mathematical Ackermann function is defined as follows:
//
//    A(m,n) =   n+1              if m=0
//               A(m-1,1)         if m>0 and n=0
//               A(m-1, A(m,n-1)) if m>0 and n>0
//
// TO DO 1: Write a function that calculates the Ackermann function according to the definition above
//          Test the program with very small values first!
// TO DO 2: Extend the function such that it counts the number of functions calls (use a global variable counter)
//          Print the function arguments and current count every x function calls.
// TO DO 3: Count the amount of recursively called functions (which are not yet completed) and print them as well
// TO DO 4: Use static variables in ackermann for counting rather than global variables.
// TO DO 5: Optional: Visualize the current recursion depth with bars of ascii-characters: xxxxxxxxxxxxxxxxxx
// TO DO 6: Optional: Provide values m and n via the command line
//          Allow in addition the option '-v' (verbose), to switch on output of intermediate results

#include <stdio.h>

// Ackermann function with static variables for counting
int ackermannFunction(int m, int n) {
    static int ackermannCounter = 0;
    static int activeCalls = 0;

    ackermannCounter += 1;
    activeCalls += 1;

    // Print the function arguments and current count every 1000 function calls
    if (ackermannCounter % 1000 == 0) {
        printf("Function call %d: A(%d, %d), Active calls: %d\n", ackermannCounter, m, n, activeCalls);
    }

    int result;
    if (m == 0) {
        result = n + 1;
    } else if (m > 0 && n == 0) {
        result = ackermannFunction(m - 1, 1);
    } else if (m > 0 && n > 0) {
        result = ackermannFunction(m - 1, ackermannFunction(m, n - 1));
    } else {
        result = -1; // This line should never be reached
    }

    activeCalls -= 1;
    return result;
}

int main(int argc, char *argv[]) {
    int n, m, results;
    printf("Value for m: ");
    scanf("%d", &m);
    printf("Value for n: ");
    scanf("%d", &n);

    results = ackermannFunction(m, n);
    printf("Ackermann(%d, %d) = %d\n", m, n, results);

    return 0;
}
