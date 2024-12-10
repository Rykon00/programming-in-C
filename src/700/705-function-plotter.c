/* Function_plotter.c
   This program uses pointers to functions, which are passed as arguments in function calls.

    TO DO 1: DONE!!! Have a look at the program and see how function pointers are used.
    TO DO 2: DONE!!! Extend the draw_function such that the range for x and y can be passed:
                         Define a struct range, which provides values for min, max and step.
    TO DO 3: DONE!!! Extend the draw_function, such that two functions
             can be passed to the draw function and are shown in the same diagram.
                         Use a NULL pointer to indicate that there is no second function to display.
    TO DO 4: Add more functions and a menu to flexibly choose
                 which functions to show (use two function pointers).
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double minimum;
    double maximum;
    double stepValue;
} range;

// Mathematical functions to be displayed
double my_function(double x) {
    return 1.5 * sin(x);
}

double another_function(double x) {
    return cos(x);
}

double yet_another_function(double x) {
    return tan(x);
}

// Draw function using ASCII art
void draw_function(double (*fn_ptr1)(double), double (*fn_ptr2)(double), range x_range, range y_range) {
    double x, y1, y2;
    int width = 80;  // Width of the plot
    int height = 20; // Height of the plot
    char plot[height][width];

    // Initialize the plot with spaces
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            plot[i][j] = ' ';
        }
    }

    // Plot the functions
    for (x = x_range.minimum; x <= x_range.maximum; x += x_range.stepValue) {
        y1 = fn_ptr1(x);
        if (y1 >= y_range.minimum && y1 <= y_range.maximum) {
            int x_pos = (int)((x - x_range.minimum) / (x_range.maximum - x_range.minimum) * (width - 1));
            int y_pos = (int)((y_range.maximum - y1) / (y_range.maximum - y_range.minimum) * (height - 1));
            plot[y_pos][x_pos] = '*';
        }
        if (fn_ptr2 != NULL) {
            y2 = fn_ptr2(x);
            if (y2 >= y_range.minimum && y2 <= y_range.maximum) {
                int x_pos = (int)((x - x_range.minimum) / (x_range.maximum - x_range.minimum) * (width - 1));
                int y_pos = (int)((y_range.maximum - y2) / (y_range.maximum - y_range.minimum) * (height - 1));
                plot[y_pos][x_pos] = '+';
            }
        }
    }

    // Add axes
    int x_axis = (int)((0 - y_range.minimum) / (y_range.maximum - y_range.minimum) * (height - 1));
    int y_axis = (int)((0 - x_range.minimum) / (x_range.maximum - x_range.minimum) * (width - 1));

    if (x_axis >= 0 && x_axis < height) {
        for (int j = 0; j < width; j++) {
            plot[x_axis][j] = '-';
        }
    }

    if (y_axis >= 0 && y_axis < width) {
        for (int i = 0; i < height; i++) {
            plot[i][y_axis] = '|';
        }
    }

    // Print the plot
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", plot[i][j]);
        }
        printf("\n");
    }
}

// Menu to select functions
void menu() {
    int choice1, choice2;
    double (*fn_ptr1)(double) = NULL;
    double (*fn_ptr2)(double) = NULL;

    range x_range = {0, 10, 0.1};
    range y_range = {-2, 2, 0.1};

    printf("Select the first function to plot:\n");
    printf("1. 1.5 * sin(x)\n");
    printf("2. cos(x)\n");
    printf("3. tan(x)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch (choice1) {
    case 1:
        fn_ptr1 = my_function;
        break;
    case 2:
        fn_ptr1 = another_function;
        break;
    case 3:
        fn_ptr1 = yet_another_function;
        break;
    default:
        printf("Invalid choice\n");
        return;
    }

    printf("Select the second function to plot (or 0 for none):\n");
    printf("0. None\n");
    printf("1. 1.5 * sin(x)\n");
    printf("2. cos(x)\n");
    printf("3. tan(x)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice2);

    switch (choice2) {
    case 0:
        fn_ptr2 = NULL;
        break;
    case 1:
        fn_ptr2 = my_function;
        break;
    case 2:
        fn_ptr2 = another_function;
        break;
    case 3:
        fn_ptr2 = yet_another_function;
        break;
    default:
        printf("Invalid choice\n");
        return;
    }

    draw_function(fn_ptr1, fn_ptr2, x_range, y_range);
}

int main() {
    menu();
    return 0;
}
