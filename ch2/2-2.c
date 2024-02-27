#include <stdio.h>

#define MAXLINE 1000

int main()
{
  char s[MAXLINE];

  int end = 0;
  int i = 0;

  while (!end) {
    char c = getchar();
    if (i >= MAXLINE - 1) {
      end = 1;
    }
    if (c == '\n') {
      end = 1;
    }
    if (c == EOF) {
      end = 1;
    }
    s[i++] = c;
  }
  printf("%s", s);
  return 0;
}
