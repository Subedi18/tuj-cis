/*
 ***************************************************************
 *  Program: Number Letter Count (Project Euler Problem 17)     *
 *                                                             *
 *  Description:                                               *
 *  This program calculates the total number of letters used   *
 *  to write all numbers from 1 to 1000 in English words.      *
 *                                                             *
 *  Rules:                                                     *
 *  - Spaces and hyphens are not counted                       *
 *  - "And" is included (British English usage)                *
 *  - Each number is analyzed based on its word representation *
 *                                                             *
 *  Output:                                                    *
 *  Prints the final count of letters used.                    *
 *                                                             *
 *  Example:                                                   *
 *  342 → "three hundred and forty two" → 23 letters           *
 *  115 → "one hundred and fifteen" → 20 letters               *
 *                                                             *
 *  Final Answer: 21124 letters (from 1 to 1000)               *
 ***************************************************************
*/

#include <stdio.h>

/*
 * Function: one_to_nineteen
 * -------------------------
 * Returns the number of letters in the English word for numbers 1 to 19.
 * Example: 3 → "three" → 5 letters
 * 
 * Parameters:
 *   n - An integer between 1 and 19
 * 
 * Returns:
 *   The number of letters in the word representation of n
 */
int one_to_nineteen(int n) {
    int letters[] = {
        0,  // 0 (unused)
        3,  // one
        3,  // two
        5,  // three
        4,  // four
        4,  // five
        3,  // six
        5,  // seven
        5,  // eight
        4,  // nine
        3,  // ten
        6,  // eleven
        6,  // twelve
        8,  // thirteen
        8,  // fourteen
        7,  // fifteen
        7,  // sixteen
        9,  // seventeen
        8,  // eighteen
        8   // nineteen
    };
    return letters[n];
}

/*
 * Function: tens_place
 * --------------------
 * Returns the number of letters in the English word for tens values (20, 30, ..., 90).
 * Example: 4 → "forty" → 5 letters
 * 
 * Parameters:
 *   n - Tens digit (from 2 to 9)
 * 
 * Returns:
 *   The number of letters in the word representation of that tens place
 */
int tens_place(int n) {
    int letters[] = {
        0,  // 0 (unused)
        0,  // 1 (10–19 handled separately)
        6,  // twenty
        6,  // thirty
        5,  // forty
        5,  // fifty
        5,  // sixty
        7,  // seventy
        6,  // eighty
        6   // ninety
    };
    return letters[n];
}

/*
 * Function: number_letter_count
 * -----------------------------
 * Calculates the number of letters used to write a number (1–1000) in English words,
 * following British English rules. Spaces and hyphens are not counted, but "and" is included.
 * 
 * Example:
 *   342 → "three hundred and forty two" → 23 letters (no spaces/hyphens)
 * 
 * Parameters:
 *   n - An integer between 1 and 1000
 * 
 * Returns:
 *   The number of letters used to write the number in words
 */
int number_letter_count(int n) {
    int count = 0;

    if (n == 1000) {
        return 3 + 8; // "one thousand" = 11 letters
    }

    if (n >= 100) {
        count += one_to_nineteen(n / 100); // "X hundred"
        count += 7;                         // "hundred"

        if (n % 100 != 0) {
            count += 3; // "and"
        }

        n = n % 100; // Remove hundreds digit to process tens/ones
    }

    if (n >= 20) {
        count += tens_place(n / 10); // e.g., 42 → 4 → "forty"
        n = n % 10;
    }

    if (n > 0) {
        count += one_to_nineteen(n); // 1 to 19
    }

    return count;
}

/*
 * Function: main
 * --------------
 * Calculates the total number of letters used to write all numbers from 1 to 1000
 * in English words, following British English formatting.
 * 
 * Output:
 *   Prints the final count of letters used
 */
int main() {
    int total = 0;

    for (int i = 1; i <= 1000; i++) {
        total += number_letter_count(i);
    }

    printf("Total number of letters used from 1 to 1000: %d\n", total);
    return 0;
}