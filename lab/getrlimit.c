#include <sys/resource.h>
#include <stdio.h>

int main()
{
  struct rlimit r_limit;
  getrlimit(RLIMIT_CPU, &r_limit);
  printf("Soft limit: %llu\n", r_limit.rlim_cur);
  return 0;
}