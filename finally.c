#include <stdio.h>

void checkGrade(int grade) {
    if (grade > 70) {
        printf("Result: Pass ✅\n");
    } else {
        printf("Result: Fail ❌\n");
    }
}

int main() {
    int finalGrade;

    printf("Enter your final grade (0–100): ");
    scanf("%d", &finalGrade);

    checkGrade(finalGrade);

    return 0;
}
