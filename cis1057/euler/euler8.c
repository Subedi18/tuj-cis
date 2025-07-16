#include <stdio.h>    // For printf, fopen, fgetc, fclose, EOF
#include <stdlib.h>   // For EXIT_SUCCESS, EXIT_FAILURE
#include <stdint.h>   // For uint64_t to hold the large product
#include <ctype.h>    // For isdigit()  <-- THIS IS THE MISSING LINE

#define INPUT_FILE "data/euler8.txt"
#define PRODUCT_LENGTH 13
#define NUM_DIGITS 1000

int main(int argc, char *argv[]) 
{  
    char digits[NUM_DIGITS + 1];
    int count = 0;
    int c;

    FILE *file = fopen(INPUT_FILE, "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

  

    while ((c = fgetc(file)) != EOF && count < NUM_DIGITS) {
        if (isdigit(c)) { // The compiler now knows what this function is
            digits[count] = c;
            count++;
        }
    }
    digits[count] = '\0';
    fclose(file);

    if (count < PRODUCT_LENGTH) 
    {
        printf("Error: Not enough digits in the file.\n");
        return EXIT_FAILURE;
    }

    uint64_t max_product = 0;

    for (int i = 0; i <= count - PRODUCT_LENGTH; i++) 
    {
        uint64_t current_product = 1;
        for (int j = 0; j < PRODUCT_LENGTH; j++) 
        {
            current_product *= (digits[i + j] - '0');
        }

        if (current_product > max_product) 
        {
            max_product = current_product;
        }
    }

    printf("The greatest product of %d adjacent digits is: %llu\n", PRODUCT_LENGTH, (unsigned long long)max_product);

    return EXIT_SUCCESS;
}