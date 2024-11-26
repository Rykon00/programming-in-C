// hanoi.c Towers of hanoi
// TO DO: Extend the programm such that it creates a graphical output of the disks on the three rods
//        introduce a function display(), which is called from hanoi()
//        Use global or static variables to keep the status of the disk towers.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TOWERS 3               // change amount of towers
#define MAX_DISKS 20               // change amount of maximum disks
int towers[NUM_TOWERS][MAX_DISKS]; // Array to represent towers
int num_disks;                     // Numbers of disks
int allMoves = 0;                  // counter to output, the moves up until this point

void initializeTowers(int n) { // initialize disks, by stacking them on the first tower
    num_disks = n;
    for (int i = 0; i < NUM_TOWERS; i++) {
        for (int j = 0; j < MAX_DISKS; j++) {
            towers[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        towers[0][MAX_DISKS - 1 - i] = n - i; // Initialize the first tower with disks from the bottom
    }
}

void display() { // display() function
    for (int i = 0; i < MAX_DISKS; i++) {
        for (int j = 0; j < NUM_TOWERS; j++) {
            if (towers[j][i] == 0) {
                printf("|     ");
            } else {
                printf("| %3d ", towers[j][i]);
            }
        }
        printf("|\n"); // line break at the end of each line
    }
    printf(" ----- ----- ----- \n");                         // final bottom line, to cap ends off
    printf("Needed moves until this Step: %d \n", allMoves); // printf to show needed moves up until this point
    nanosleep(&(struct timespec){0, 10000000}, NULL);        // 0,1 sec delay before each print
}

void moveDisk(int start, int goal) {
    allMoves += 1;
    int disk = 0;
    for (int i = 0; i < MAX_DISKS; i++) {
        if (towers[start - 1][i] != 0) {
            disk = towers[start - 1][i];
            towers[start - 1][i] = 0;
            break;
        }
    }
    for (int i = MAX_DISKS - 1; i >= 0; i--) {
        if (towers[goal - 1][i] == 0) {
            towers[goal - 1][i] = disk;
            break;
        }
    }
}

void hanoi(int n, int start, int goal, int helper) {
    if (n > 0) {
        hanoi(n - 1, start, helper, goal);
        printf("move disk from %d to %d\n", start, goal);
        moveDisk(start, goal);
        display();
        hanoi(n - 1, helper, goal, start);
    }
}

int main() {
    int n;
    for (int i = 0; i < 999; i++) { // checking if, tower height doesnt exceed, tower max limit
        printf("How many disks? ");
        scanf("%d", &n);
        if (n > MAX_DISKS) {
            printf("Invalid! Number of disks cannot exceed, tower limit!!!\n");
            i = 0;
        } else {
            i = 1000;
        }
    }

    initializeTowers(n);

    display(); // Display the initial state
    hanoi(n, 1, 3, 2);

    return EXIT_SUCCESS;
}