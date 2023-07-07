#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t page_size = getpagesize();
    printf("Page size: %zu bytes\n", page_size);

    size_t data_size = 8095; // Size of your data structure or memory allocation

    // Calculate the aligned size
    size_t aligned_size = (data_size + page_size - 1) & ~(page_size - 1);

    printf("Data size: %zu bytes\n", data_size);
    printf("Aligned size: %zu bytes\n", aligned_size);

    // Allocate memory with aligned_size
    void* aligned_memory = malloc(aligned_size);
    if (aligned_memory == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 1;
    }

    // Use the aligned_memory as needed...

    // Free the aligned memory
    free(aligned_memory);

    return 0;
}
