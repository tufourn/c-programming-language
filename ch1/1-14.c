#include <stdio.h>

int main()
{
  int num[10];
  int alpha[26];
  int c;

  for (int i = 0; i < 10; ++i) {
    num[i] = 0;
  }

  for (int i = 0; i < 26; ++i) {
    alpha[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++num[c - '0'];
    } else if (c >= 'a' && c <= 'z') {
      ++alpha[c - 'a'];
    }
  }

  for (int i = 0; i < 26; ++i) {
    putchar(i + 'a');
    for (int j = 0; j < alpha[i]; ++j) {
      putchar('#');
    }
    putchar('\n');
  }
  putchar('\n');
  for (int i = 0; i < 10; ++i) {
    putchar(i + '0');
    for (int j = 0; j < num[i]; ++j) {
      putchar('#');
    }
    putchar('\n');
  }
}
