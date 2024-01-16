#include <stdio.h>
#include "lib/utils.h"

int main()
{
  int input;
  int sum;

  do {
    printf("Enter an integer: ");
    scanf("%d", &input);
    clear_scanf_buffer();

    if (input == 0) break;

    sum += input;
    printf("Current sum: %d\n\n", sum);
  } while (1);

  printf("\nTotal sum: %d\n", sum);

  return 0;
}
