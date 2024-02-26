#include <stdio.h>

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 100;
  step = 5;

  celsius = lower;

  printf("Celcius to Fahrenheit Conversion table\n");
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32.0; 
    printf("%6.1f %3.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
