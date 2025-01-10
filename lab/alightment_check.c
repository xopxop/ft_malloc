#include <stddef.h>
#include <stdalign.h>
#include <stdio.h>

int main() {
    printf("Alignment of void*: %zu bytes\n", alignof(void*));
    printf("Alignment of max_align_t: %zu bytes\n", alignof(max_align_t));
    return 0;
}
