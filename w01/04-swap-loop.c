#include <stdio.h>
#include "lib/utils.h"

int main()
{
  int x, y;

  do {
    printf("Enter x: ");
    scanf("%d", &x);
    clear_scanf_buffer();

    // if x=0 then exit loop
    if (x == 0) break;

    printf("Enter y: ");
    scanf("%d", &y);
    clear_scanf_buffer();

    // if y=0 then exit loop
    if (y == 0) break;

    // swap x and y
    int t = x;
    x = y;
    y = t;

    printf("x: %d, y: %d\n\n", x, y);
  } while(1);

  return 0;
}