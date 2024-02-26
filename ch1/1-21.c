#include <stdio.h>

#define TAB_LENGTH 8

int main()
{
  int c;

  int nspace = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ') {
      ++nspace;
      if (nspace >= TAB_LENGTH) {
        nspace -= TAB_LENGTH;
        putchar('\t');
      }
    } else {
      for (int i = 0; i < nspace; ++i) {
        putchar(' ');
      }
      nspace = 0;
      putchar(c);
    }
  }
  return 0;
}
