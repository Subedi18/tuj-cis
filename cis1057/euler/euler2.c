#include <stdlib.h>
#include <stdio.h>
#define LIMIT 4000000

int main(void) {
    int a =1; 
    int b=2; 
    int sum=0;

    

while (b <= LIMIT) {
        if (b % 2 == 0) {
            sum += b;
   }
    int temp = a + b;   
    a = b;
    b = temp;
}
  printf("Sum of even Fibonacci numbers less than %d: %d\n", LIMIT, sum);
    return EXIT_SUCCESS;
}
