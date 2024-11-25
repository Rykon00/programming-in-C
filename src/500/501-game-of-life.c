/* Game of life
The "game of life" is an old and very simple approach of simulating evolution
A 2-dimensional field of cells is regarded with a cell being either empty/dead (0) or occupied/alive (1)
The intial state can be chosen e.g. manually or using some random operations.

The further evolution is governed by the following rules:

Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent.
At each step in time, the following transitions occur:
   1. Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
   2. Any live cell with more than three live neighbours dies, as if by overcrowding.
   3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
   4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.

The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed � births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.)  The rules continue to be applied repeatedly to create further generations.

see: http://en.wikipedia.org/wiki/Conway's_Game_of_Life
*/

// TO DO: Complete the programm such that it simulates the game of life.
//        Do it as teamwork (e.g. in teams with 2 or 3)
//        and benefit from being able to develop functions independently and integrate them into the final program.
// TO DO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states.
// TO DO optional 2: let the program find a start state such that the system stays alive and unstable for as long as possible
// TO DO optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
// TO DO optional 4: extend the program such that the content of the cells can be edited by the user.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For usleep function

// TO DO: DONE!!! initialize cells, set most to 0, some to 1
void initialize_cells(char cells[30][50]) {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 50; j++) {
            if (rand() % 10 == 0) { // Use rand() to generate random numbers
                cells[i][j] = 'X';  // 10% chance to be 'X'
            } else {
                cells[i][j] = ' '; // 90% chance to be ' '
            }
        }
    }
}

// TO DO: DONE!!! Write a function that counts the occupied cells
int count_cells(char cells[30][50]) {
    int count = 0;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 50; j++) {
            if (cells[i][j] == 'X') { // Assuming 'X' represents an occupied cell
                count++;
            }
        }
    }
    return count;
}

// TO DO: DONE!!! Write output function to print the cells
void display_cells(char cells[30][50]) {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 50; j++) {
            printf("%c", cells[i][j]);
        }
        printf("\n");
    }
    // Counted Cells output & additional information
    printf("Number of Cells alive: %i\n", count_cells(cells));
    if (count_cells(cells) == 0) {
        printf("Population extinct!\n");
    } else {
        printf("Population is still alive!\n");
    }
    usleep(500000);
}

// TO DO: Write a function to calculate the next evolution step
void evolution_step(char cells[30][50]) {
    char cellsCopy[30][50];
    int x, y;
    // creating duplicate of cells[][]
    for (y = 0; y < 30; y++) {
        for (x = 0; x < 50; x++) {
            cellsCopy[y][x] = cells[y][x];
        }
    }

    int offsets[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    // iterating the whole cells[][]
    for (y = 0; y < 30; y++) {
        for (x = 0; x < 50; x++) {
            int aliveCells = 0;

            // Check surrounding cells of each cell in cells[][]
            for (int k = 0; k < 8; k++) {
                int NIx = x + offsets[k][1];
                int NIy = y + offsets[k][0];

                if (NIx >= 0 && NIx < 50 && NIy >= 0 && NIy < 30) {
                    if (cells[NIy][NIx] == 'X') {
                        aliveCells++;
                    }
                }
            }

            // Apply the rules of the game
            if (cells[y][x] == 'X') { // Cell is currently alive
                if (aliveCells < 2 || aliveCells > 3) {
                    cellsCopy[y][x] = ' '; // Cell dies
                }
            } else { // Cell is currently dead
                if (aliveCells == 3) {
                    cellsCopy[y][x] = 'X'; // Cell becomes alive
                }
            }
        }
    }

    // Copy the new state back to the original cells array
    for (y = 0; y < 30; y++) {
        for (x = 0; x < 50; x++) {
            cells[y][x] = cellsCopy[y][x];
        }
    }
}

// Main program
int main() {
    char cells[30][50];
    initialize_cells(cells);

    while (1) {
        display_cells(cells);

        // Leave loop if there are no more occupied cells
        if (count_cells(cells) == 0) {
            break;
        }

        // input for next step
        printf("Press enter");

        // next evolution step
        evolution_step(cells);
    }
}