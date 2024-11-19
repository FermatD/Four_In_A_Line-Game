#include "aligned.h"

// Function to display the grid
void display_grid(TBoard A) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i + 1); // Display row numbers
        for (int j = 0; j < COLS; j++) {
            printf("%c ", A[i][j]); // Print the cell value (disc or empty space)
        }
        printf("\n");
    }

    // Print column headers aligned with the grid
    printf("  ");
    for (int j = 1; j <= COLS; j++) {
        printf("%d ", j);
    }
    printf("\n");
}

// Function to drop a disc into a column
int drop_disc(TBoard A, int col, char disc) {
    int done = 0; // Flag to indicate if the disc was successfully dropped
    int i = ROWS - 1; // Start from the bottom-most row

    // Check if the column number is valid
    if ((col >= 1) && (col <= COLS)) {
        while ((done != 1) && (i >= 0)) { // Iterate upwards through the column
            if (A[i][col - 1] == ' ') { // Check if the cell is empty
                A[i][col - 1] = disc; // Drop the disc in the cell
                done = 1; // Mark as successful
            }
            i = i - 1; // Move to the row above
        }
    } else {
        done = -1; // Invalid column number
    }

    return done; // Return the status
}

// Function to play the game
void play_game(TBoard A) {
    int done, stop = 0, placed_disc = 0, player = 0, col;
    char disc;

    empty_grid(A); // Initialize the grid to be empty

    do {
        // Determine the current player and their disc
        if ((player % 2) == 0) {
            disc = 'X'; // Player 1 uses 'X'
            printf("\nPlayer 1!!!\n");
        } else {
            printf("\nPlayer 2!!!\n");
            disc = 'O'; // Player 2 uses 'O'
        }

        // Prompt the player for input and validate it
        int valid_move = 0;
        while (!valid_move) {
            printf("\nEnter a column to drop the disc: ");
            scanf("%d", &col);

            done = drop_disc(A, col, disc); // Attempt to drop the disc in the chosen column

            if (done == 1) {
                valid_move = 1; // Valid move
                display_grid(A); // Display the updated grid
                player = player + 1; // Switch to the next player
                placed_disc = placed_disc + 1; // Increment the total number of discs placed
            } else if (done == 0) {
                printf("\nChosen column is full. Choose another.\n");
            } else {
                printf("\nInvalid column number. Choose another.\n");
            }
        }

        // Check if the game is won
        int align = is_aligned(A); // Check if there is an alignment (win condition)
        if ((align == 1) && (disc == 'X')) {
            printf("\nGame Over! Player 1 wins!\n");
            stop = 1; // End the game
        } else if ((align == 1) && (disc == 'O')) {
            printf("\nGame Over! Player 2 wins!\n");
            stop = 1; // End the game
        } else if ((align == 1) && !((disc == 'X') || (disc == 'O'))) {
            printf("\nError: Unknown player type %c\n", disc);
        }
    } while ((stop == 0) && (placed_disc < 25)); // Continue until there is a winner or the grid is full

    if (stop == 0) {
        printf("\nGame over! It is a tie!\n");
    }
}

// Main function
int main() {
    TBoard c4grid; // Declare the game grid

    empty_grid(c4grid); // Initialize the grid
    display_grid(c4grid); // Display the empty grid
    printf("\nWelcome to Connect Four Game\nPlayer 1: X\nPlayer 2: O\n");
    play_game(c4grid); // Start the game

    return 0;
}
