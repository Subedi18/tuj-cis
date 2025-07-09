#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 1100  // Extra room for safety
#define TARGET_LENGTH 1000

void reverse(char *string, int length);
void add_into(char *sum, char *addend);

int main() {
    char f1[MAX_DIGITS] = {'1', '\0'};   // F(1)
    char f2[MAX_DIGITS] = {'1', '\0'};   // F(2)
    char fn[MAX_DIGITS] = {0};

    reverse(f1, strlen(f1));
    reverse(f2, strlen(f2));

    int index = 2;

    while (1) {
        memset(fn, 0, sizeof(fn));
        add_into(fn, f1);
        add_into(fn, f2);
        index++;

        // Check digit length
        int length = strlen(fn);
        if (length >= TARGET_LENGTH) {
            printf("Index of first Fibonacci number with %d digits: %d\n", TARGET_LENGTH, index);
            break;
        }

        // Shift: f1 = f2, f2 = fn
        strcpy(f1, f2);
        strcpy(f2, fn);
    }

    return EXIT_SUCCESS;
}

void reverse(char *string, int length) {
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
}

void add_into(char *sum, char *addend) {
    for (int i = 0, carry = 0, add_flag = 1, sum_flag = 1; add_flag || sum_flag; i++) {
        add_flag = add_flag && addend[i];
        sum_flag = sum_flag && sum[i];

        int subtotal = (add_flag ? addend[i] : '0') + carry - '0';
        if (subtotal) {
            sum[i] = (sum_flag ? sum[i] : '0') + subtotal;
            carry = sum[i] > '9';
            sum[i] -= carry * 10;
        } else if (!add_flag) {
            if (!sum_flag) sum[i] = 0;
            break;
        } else if (!sum_flag) {
            sum[i] = '0';
        }
    }
}
