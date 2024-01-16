#include "utils.h"
#include <stdio.h>

void clear_scanf_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}
