#include <stdio.h>

int main()
{
  int c;
  int last_c = '\0';

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (last_c != ' ' && last_c != '\t' && last_c && '\n') {
        putchar('\n');
      }
    } else {
      putchar(c);
    }
    last_c = c;
  }
}
