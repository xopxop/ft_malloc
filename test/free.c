#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
  char *str = strdup("Hello world!");
  printf("%s\n", str);
  free(str);
  printf("%s\n", str);
  return 0;
}