

#include <stdlib.h>
#include <stdio.h>

/**
 * PROJECT EULER #11
 * Largest Product in a Grid
 *
 * In the 20 x 20 grid below, four numbers along a diagonal line have
 * been marked in red.
 *
 * (data available in data/euler11.txt)
 *
 * The product of these numbers is 26 x 63 x 78 x 14 = 1788696.
 *
 * What is the greatest product of four adjacent numbers in the same
 * direction (up, down, left, right, or diagonally) in the 20 x 20 grid?
 */

#define INPUT_FILE "data/euler11.txt"
#define PRODUCT_LENGTH 4
#define GRID_SIZE 20

// Function to read the grid from file
int read_grid(int grid[GRID_SIZE][GRID_SIZE], const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }
    
    // Read 20x20 grid of integers
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (fscanf(file, "%d", &grid[i][j]) != 1) {
                printf("Error: Could not read grid data\n");
                fclose(file);
                return 0;
            }
        }
    }
    
    fclose(file);
    return 1;
}

// Function to calculate product of PRODUCT_LENGTH numbers starting at (row, col) in given direction
long long calculate_product(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int dr, int dc) {
    long long product = 1;
    
    for (int i = 0; i < PRODUCT_LENGTH; i++) {
        int current_row = row + i * dr;
        int current_col = col + i * dc;
        
        // Check bounds
        if (current_row < 0 || current_row >= GRID_SIZE || 
            current_col < 0 || current_col >= GRID_SIZE) {
            return 0; // Invalid position
        }
        
        product *= grid[current_row][current_col];
    }
    
    return product;
}

// Function to find maximum product in all directions
long long find_max_product(int grid[GRID_SIZE][GRID_SIZE]) {
    long long max_product = 0;
    
    // Check all possible starting positions
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            
            // Direction vectors: (row_delta, col_delta)
            // Right (horizontal)
            long long product = calculate_product(grid, row, col, 0, 1);
            if (product > max_product) {
                max_product = product;
            }
            
            // Down (vertical)
            product = calculate_product(grid, row, col, 1, 0);
            if (product > max_product) {
                max_product = product;
            }
            
            // Diagonal down-right
            product = calculate_product(grid, row, col, 1, 1);
            if (product > max_product) {
                max_product = product;
            }
            
            // Diagonal down-left
            product = calculate_product(grid, row, col, 1, -1);
            if (product > max_product) {
                max_product = product;
            }
        }
    }
    
    return max_product;
}

// Function to print the grid (for debugging)
void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%02d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int grid[GRID_SIZE][GRID_SIZE];
    
    // Read the grid from file
    if (!read_grid(grid, INPUT_FILE)) {
        return EXIT_FAILURE;
    }
    
    printf("Grid loaded successfully!\n");
    
    // Uncomment to see the grid
    // print_grid(grid);
    
    // Find the maximum product
    long long max_product = find_max_product(grid);
    
    printf("The greatest product of four adjacent numbers is: %lld\n", max_product);
    
    return EXIT_SUCCESS;
}


