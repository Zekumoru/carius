#include <stdio.h>

int main()
{
  double n1, n2, result;
  char op;
  int error;

  printf("Enter an expression (+, -, *, /): ");
  scanf("%lf%c%lf", &n1, &op, &n2);

  error = 0;
  switch (op) {
    case '+':
      result = n1 + n2;
      break;
    case '-':
      result = n1 - n2;
      break;
    case '*':
      result = n1 * n2;
      break;
    case '/':
      if (n2 == 0) {
        printf("Error: division by zero\n");
        error = -1;
      } else {
        result = n1 / n2;
      }
      break;
    case ' ':
      printf("Error: there must be no spaces in expression\n");
      error = -1;
      break;
    default:
      printf("Error: unsupported operator '%c'\n", op);
      error = -1;
  }

  if (!error) {
    printf("Result is: %lf\n", result);
  }

  return 0;
}