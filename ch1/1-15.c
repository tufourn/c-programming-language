#include <stdio.h>

float c_to_f(int c);

int main()
{

  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  printf("Celsius to Fahrenheit Conversion table\n");
  while (celsius <= upper) {
    fahr = c_to_f(celsius);
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius += step;
  }
}

float c_to_f(int c)
{
  return (9.0 / 5.0) * c + 32.0;
}

