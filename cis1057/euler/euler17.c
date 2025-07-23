

/**
 * PROJECT EULER #17
 * Number Letter Counts
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four,
 * five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written
 * out in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred
 * and forty-two) contains 23 letters and 115 (one hundred and fifteen)
 * contains 20 letters. The use of "and" when writing out numbers is in
 * compliance with British usage.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* ones[] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
};

char* tens[] = {
    "", "", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
};

// Convert number to readable word form with spaces/hyphens
void numberToWordsFormatted(int n, char* formatted) {
    formatted[0] = '\0'; // Clear output string

    if (n == 1000) {
        strcat(formatted, "one thousand");
        return;
    }

    if (n >= 100) {
        strcat(formatted, ones[n / 100]);
        strcat(formatted, " hundred");
        if (n % 100 != 0) {
            strcat(formatted, " and ");
        }
        n %= 100;
    }

    if (n >= 20) {
        strcat(formatted, tens[n / 10]);
        if (n % 10 != 0) {
            strcat(formatted, "-");
            strcat(formatted, ones[n % 10]);
        }
    } else if (n > 0) {
        strcat(formatted, ones[n]);
    }
}


int countLetters(const char* word) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            count++;
        }
    }
    return count;
}


int main() {
    int number;
    char formatted[100];

    printf("Enter a number between 1 and 1000: ");
    scanf("%d", &number);

    if (number < 1 || number > 1000) {
        printf("Out of range. Try again.\n");
        return 1;
    }

    numberToWordsFormatted(number, formatted);
    printf("In words          : %s\n", formatted);
    printf("Number of letters : %d\n", countLetters(formatted));

    return 0;
}
