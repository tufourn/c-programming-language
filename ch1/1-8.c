#include <stdio.h>

int main()
{
  int c, b, t, n;

  b = 0;
  t = 0;
  n = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') ++n;
    if (c == '\t') ++t;
    if (c == ' ') ++b;
  }
  printf("newlines: %d\nblanks: %d\ntabs: %d\n", n, b, t);
}
