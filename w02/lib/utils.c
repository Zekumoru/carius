#include "utils.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>

void println(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  vprintf(fmt, args);
  printf("\n");

  va_end(args);
}

char *getln()
{
  int size = 1;
  // dynamically allocate space in memory, starting with length of 1
  int allocSize = 1;
  char *line = malloc(allocSize);
  line[0] = '\0';

  char ch;
  while ((ch = getchar()) != '\n' && ch != '\r' && ch != EOF) {
    // copy input to string 'line'
    line[size - 1] = ch;
    
    size++;
    if (size >= allocSize) {
      // reallocate space by 2
      allocSize *= 2;
      line = (char *)realloc(line, allocSize);
    }
  }

  // create string which has length of the actual size
  // instead of having empty characters because of allocSize
  char *string = malloc(size);
  memcpy(string, line, size);
  string[size - 1] = '\0';
  free(line);

  return string;
}

double toDouble(const char *string, ...)
{
  double num = 0.0;
  int pos = 0;
  bool isNeg = false;
  bool dotFound = false;
  bool useComma = false;

  // get from optional second argument if
  // comma is toggled as a decimal separator
  va_list args;
  va_start(args, string);
  useComma = va_arg(args, int) == true;
  va_end(args);

  // ignore leading spaces
  for (int i = 0; isspace(string[i]); i++, pos++);

  // check if the number is negative
  isNeg = string[pos] == '-';
  if (isNeg) pos++;

  for (int decPlace = 1; isdigit(string[pos]) || string[pos] == '.' || (useComma && string[pos] == ','); pos++) {
    if (string[pos] == '.' || (useComma && string[pos] == ',')) {
      // if this is the second decimal separator (dot or comma)
      // then stop parsing
      if (dotFound) break;

      // found first decimal separator
      dotFound = true;
      continue;
    }

    // convert current char digit to int
    int digit = string[pos] - '0';

    if (!dotFound) {
      // handle whole part
      num *= 10;
      num += digit;
    } else {
      // handle fractional part
      double dec = digit / pow(10, decPlace);
      decPlace++;
      num += dec;
    }
  }

  // negate if it were set to negative earlier
  if (isNeg) num *= -1;

  return num;
}

double getDouble()
{
  char *input = getln();
  double num = toDouble(input);
  free(input);
  return num;
}
