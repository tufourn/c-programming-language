#include <stdio.h>

#define MAXSTR 10000

#define TRUE (1 == 1)
#define FALSE !TRUE


int get_str(char str[], int len);
void remove_comments(char str[], char new_str[]);

int main()
{
  char str[MAXSTR];
  char new_str[MAXSTR];

  get_str(str, MAXSTR);

  remove_comments(str, new_str);

  printf("%s", new_str);

  return 0;
}

int get_str(char str[], int len)
{
  int c;
  int i = 0;
  while (i < len - 1 && (c = getchar()) != EOF) {
    str[i++] = c;
  }
  str[i] = '\0';
  return i;
}

void remove_comments(char str[], char new_str[])
{
  int in_quote = FALSE;
  int in_line = FALSE;
  int in_block = FALSE;

  int i = 0, j = 0;;
  while (str[i] != '\0') {
    if (!in_block) {
      if (!in_quote && str[i] == '"') {
        in_quote = TRUE;
      } else if (in_quote && str[i] == '"') {
        in_quote = FALSE;
      }
    }
    if (!in_quote) {
      if (str[i] == '/' && str[i + 1] == '*' && !in_line) {
        in_block = TRUE;
      }
      if (str[i] == '*' && str[i + 1] == '/') {
        in_block = FALSE;
        i += 2;
      }
      if (str[i] == '/' && str[i + 1] == '/') {
        in_line = TRUE;
      }
      if (str[i] == '\n') {
        in_line = FALSE;
      }
      if (in_line || in_block) {
        ++i;
      } else if (!in_line || !in_block) {
        new_str[j++] = str[i++];
      }
    } else {
      new_str[j++] = str[i++];
    }
  }
  new_str[j] = '\0';
}
