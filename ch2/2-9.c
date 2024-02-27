#include <stdio.h>

int bitcount(int x);

int main()
{
  int x = 0b00111000;
  printf("%d\n", bitcount(x));
  return 0;
}

int bitcount(int x)
{
  int count = 0;
  while (x) {
    x &= (x - 1);
    ++count;
  }

  return count;
}
