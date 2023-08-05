#include "sys/resource.h"
#include "stdio.h"

int main()
{
  struct rlimit rlp;
  
  getrlimit(RLIMIT_AS, &rlp);
  printf("rlim_cur %llu\n", rlp.rlim_cur);
  printf("rlim_max %llu\n", rlp.rlim_max);
  printf("Maximum value of size_t: %zu\n", SIZE_MAX);
  if (SIZE_MAX > rlp.rlim_cur)
    printf("bigger\n");
  return 0;
}