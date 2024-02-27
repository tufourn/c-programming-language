#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int htoi(char hex[]);

int main()
{
  printf("0xae234 to dec is %d\n", htoi("0xae234"));
}

int htoi(char hex[])
{
  int result = 0;
  int len = strlen(hex);

  int i = 0;

  while (i < len) {
    if (hex[i] == '0' && (hex[i+1] == 'x' || hex[i+1] == 'X')) {
      i += 2;
    }   

    int n = tolower(hex[i]);
    
    if (isdigit(n)) {
      n -= '0';
      result += n * pow(16, (len - i - 1));
    } else if (isalpha(n) && n <= 'f') {
      n = n - 'a' + 10;
      result += n * pow(16, len - i - 1);
    } else {
      printf("invalid num\n");
    }
    ++i;
  }  

  return result;
}
