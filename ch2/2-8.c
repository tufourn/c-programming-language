#include <stdio.h>

unsigned rightrot(unsigned x, int n); 

int main()
{
  unsigned int x = 0b11001100;
  printf("%b", rightrot(x, 3));
  return 0;
}

unsigned rightrot(unsigned x, int n)
{
  unsigned int msb_set = ~(~(unsigned)0 >> 1);
  int i;
  for (i = 0; i < n; ++i) {
    if (x & 1) {
      x = (x >> 1) | msb_set;
    } else {
      x = x >> 1;
    }
  }
  return x;
}
