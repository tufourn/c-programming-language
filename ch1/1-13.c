#include <stdio.h>

int main()
{
  int c, i, nwhite, nother;
  int ndigit[10];

  int max_height = 0;

  nwhite = nother = 0;
  for (i = 0; i < 10; ++i) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
      if (ndigit[c - '0'] > max_height) {
        max_height = ndigit[c - '0'];
      }
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }

  printf("digits =");
  for (i = 0; i < 10; ++i) {
    printf(" %d", ndigit[i]);
  }
  printf(", whitespace = %d, other = %d\n", nwhite, nother);

  // prints horizontal histogram
  for (i = 0; i < 10; ++i) {
    putchar('0' + i);
    for (int j = 0; j < ndigit[i]; ++j) {
      putchar('#');
    }
    putchar('\n');
  }

  putchar('\n');

  // prints vertical histogram
  for (i = max_height; i > 0; --i) {
    for (int j = 0; j < 10; ++j) {
      if (ndigit[j] >= i) {
        putchar('#');
      } else {
        putchar(' ');
      }
    }
    putchar('\n');
  }
  printf("0123456789\n");
}
