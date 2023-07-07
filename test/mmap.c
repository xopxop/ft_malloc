#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
/*
virtual memory
physical memory
*/

int main() {
  void *ptr = mmap(0, (size_t)getpagesize(), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
  printf("%p\n", ptr);
  printf("%d\n", munmap(ptr, 1));
  return (0);
}