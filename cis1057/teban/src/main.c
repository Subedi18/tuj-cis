// main.c
#include <stdio.h>
#include <stdlib.h>
#include "Allocator.h"

Allocator *alloc;

int main(void) {
alloc = Allocator_new();

printf("Enter integers (Ctrl+D on Unix/Linux/Mac or Ctrl+Z on Windows to end):\n");

// First, read all integers into a temporary array to count them
int temp_numbers[1000]; // Assuming max 1000 integers
int count = 0;
int input;

// Read integers until EOF
while (scanf("%d", &input) == 1 && count < 1000) {
temp_numbers[count] = input;
count++;
}

// Now allocate space in the allocator for all integers at once
int *numbers = Allocator_push(alloc, count * sizeof(int));

// Copy all integers to the allocator array
for (int i = 0; i < count; i++) {
numbers[i] = temp_numbers[i];
}

// Display all stored integers
printf("\nStored integers:\n");
for (int i = 0; i < count; i++) {
printf("Integer %d: %d\n", i + 1, numbers[i]);
}

// Clean up
Allocator_clear(alloc);
free(alloc);

return 0;
}