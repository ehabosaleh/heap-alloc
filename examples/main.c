#include <stdio.h>
#include "heap.h"

int main() {
    int *a = heap_alloc(sizeof(int));
    int *b = heap_alloc(100);

    *a = 42;
    snprintf((char *)b, 100, "Hello mmap allocator");

    printf("%d\n", *a);
    printf("%s\n", (char *)b);

    heap_free(a);
    heap_free(b);
}

