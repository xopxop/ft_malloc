#include <sys/resource.h>

int main()
{
  struct rlimit r_limit;
  getrlimit(RLIMIT_CPU, &r_limit);
  return 0;
}