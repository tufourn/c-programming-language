#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
  unsigned int x = 0b11111111;
  printf("%b %b", x, invert(x, 1, 4));
  return 0;
}

unsigned invert(unsigned x, int p, int n)
{
  unsigned int mask1 = ~(~0 << n) << p;
  return x ^ mask1;
}
