#include <stdio.h>
#include "lib/utils.h"

int main()
{
  char c1, c2;
  int diff; // difference between c1 and c2

  printf("Enter first ASCII character: ");
  scanf("%c", &c1);
  clear_scanf_buffer();

  printf("Enter second ASCII character: ");
  scanf("%c", &c2);
  clear_scanf_buffer();

  // make c2 contain the bigger character
  if (c1 > c2) {
    char t = c1;
    c1 = c2;
    c2 = t;
  }

  // calculate difference between c1 and c2
  diff = c2 - c1;
  printf("The difference between '%c' and '%c' is %d\n", c1, c2, diff);

  // output ASCII characters between c1 and c2
  printf("\n");
  printf("Char\tDec\tOct\tHex\n");
  for (int i = c1; i <= c2; i++) {
    printf("%c\t%d\t%o\t%X\n", (char)i, i, i, i);
  }

  return 0;
}
