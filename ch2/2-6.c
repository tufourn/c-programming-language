#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
  unsigned int x = 0b11111111;
  unsigned int y = 0b0110;
  unsigned int result = setbits(x, 2, 4, y);

  printf("%b %b %b", x, y, result);

  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned mask1 = (y & ~(~0 << n)) << p;
  unsigned mask2 = ~(~(~0 << n) << p) & x;

  return mask1 | mask2;
}
