#include <stdio.h>

#define TAB_LENGTH 2

int main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (int i = 0; i < TAB_LENGTH; i++) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  }
  return 0;
}
