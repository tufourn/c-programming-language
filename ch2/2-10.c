#include <stdio.h>

char lower(char c);

int main()
{
  putchar(lower('A'));
  return 0;
}

char lower(char c)
{
  return (c >= 'A' && c <= 'Z') ? c += 'a' - 'A' : c;
}
