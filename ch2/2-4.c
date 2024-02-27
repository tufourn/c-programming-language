#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
  char s1[] = "the quick brown fox jumps over the lazy dog";
  char s2[] = "abc";

  squeeze(s1, s2);

  printf("%s\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[])
{
  int i, j, k;
  int match;
  i = j = k = 0;

  while (s1[i] != '\0') {
    k = 0;
    match = 0;

    for (k = 0; s2[k] != '\0'; k++) {
      if (s1[i] == s2[k]) {
        match = 1;
      }
    }
    
    if (!match) {
      s1[j++] = s1[i];
    }

    i++;
  }

  s1[j] = '\0';
}


