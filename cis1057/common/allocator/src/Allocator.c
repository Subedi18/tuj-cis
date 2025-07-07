/**
 * @file Allocator.c
<<<<<<< Updated upstream
 * @brief Basic linear (stack-based) allocator
=======
 * @brief Minimal implementation of Allocator to pass creation tests
 * 
 * This implementation creates a valid allocator but still fails
 * allocation tests to demonstrate incremental TDD progress.
>>>>>>> Stashed changes
 */

#include "Allocator.h"
#include <stdlib.h>
#include <stddef.h>

/**
<<<<<<< Updated upstream
 * @brief Allocator block with fixed size
 */
struct Allocator {
    char *head;     /* First open address */
    char *tail;     /* End of memory block */
};

#define DEFAULT_CAPACITY (1 << 15)  /* 32KB default capacity */

Allocator *Allocator_new(void)
{
    /* Allocate memory for the structure plus storage */
    Allocator *alloc = calloc(1, DEFAULT_CAPACITY);
    if (alloc) {
        alloc->head = (char *)(alloc + 1);
        alloc->tail = (char *)alloc + DEFAULT_CAPACITY;
=======
 * @brief Minimal allocator structure with basic state
 */
struct Allocator {
    size_t used;  /* Track bytes allocated */
};

Allocator *Allocator_new(void)
{
    /* Allocate memory for the allocator structure */
    Allocator* alloc = malloc(sizeof(Allocator));
    if (alloc) {
        alloc->used = 0;  /* Initialize to zero usage */
>>>>>>> Stashed changes
    }
    return alloc;
}

<<<<<<< Updated upstream
void *Allocator_push(Allocator *alloc, ptrdiff_t size)
{
    if (!(alloc && size)) return NULL;  // Handle NULL allocator or 0 size
    if (alloc->tail - alloc->head < size) return NULL;  // Ensure available capacity
    void *ptr = alloc->head;
    alloc->head += size;
    return ptr;
}

void Allocator_pop(Allocator *alloc, size_t size)
{
    if (!(alloc && size)) return;   // Handle NULL allocator or 0 size
    if (alloc->head - (char *)alloc + sizeof(Allocator) < size) return; // Ensure available capacity
    alloc->head -= size;
}

void Allocator_clear(Allocator *alloc)
{
    if (alloc) alloc->head = (char *)(alloc + 1);
}

size_t Allocator_used(Allocator *alloc)
{
    if (!alloc) return 0;
    return alloc->head - (char *)alloc - sizeof(Allocator);
=======
void Allocator_free(Allocator *allocator)
{
    /* Free the allocator structure (handles NULL gracefully) */
    free(allocator);
}

void *Allocator_push(Allocator *allocator, size_t size)
{
    /* Return NULL to fail all allocation tests */
    (void)allocator;
    (void)size;
    return NULL;
}

void Allocator_pop(Allocator *allocator, size_t size)
{
    /* Do nothing to fail stack behavior tests */
    (void)allocator;
    (void)size;
}

void Allocator_clear(Allocator *allocator)
{
    /* Do nothing to fail clear tests */
    (void)allocator;
}

size_t Allocator_used(Allocator *allocator)
{
    /* Return actual usage or 0 for NULL */
    if (!allocator) {
        return 0;
    }
    return allocator->used;
>>>>>>> Stashed changes
}