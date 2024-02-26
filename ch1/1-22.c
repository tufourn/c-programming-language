#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAXLINE 1000

#define BREAK_POINT 40
#define OFFSET 10

char line[MAXLINE];
char folded[MAXLINE];

int get_line(void);
void fold_line(void);

int main()
{
  extern char folded[];
  while ((get_line()) > 0) {
    fold_line();
    printf("%s", folded);
  }

  return 0;
}

void fold_line(void)
{
  extern char line[];
  extern char folded[];

  int i, j;
  int col = 0;
  int split = FALSE;
  int last_blank = 0;

  for (i = 0, j = 0; line[i] != '\0'; ++i, ++j) {
    folded[j] = line[i];

    if (folded[j] == '\n') {
      col = 0;
    }

    ++col;

    if (col == BREAK_POINT - OFFSET) {
      split = TRUE;
    }

    if (split && (folded[j] == ' ' || folded[j] == '\t')) {
      last_blank = j;
    }

    if (col == BREAK_POINT) {
      if (last_blank) {
        folded[last_blank] = '\n';
        col = j - last_blank;
        last_blank = 0;
      } else {
        folded[j++] = '-';
        folded[j] = '\n';

        col = 0;
      }
      split = FALSE;
    }
  }

  folded[j] = '\0';
}

int get_line(void)
{
  int c, i = 0;
  extern char line[];

  for (i = 0; i < MAXLINE - 1
      && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }

  if (c == '\n')
  {
    line[i++] = c;
  }

  line[i] = '\0';

  return i;
}
