#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "lib/utils.h"

/**
 * \brief Checks if a given integer is prime.
 * \param num The integer to check if prime.
 * \return A boolean value if the given integer is prime.
 */
bool isprime(int num);

int main()
{
  int num = 0;

  do {
    if (num < 0) {
      println("Error: input must be a positive integer");
    }

    printf("Enter positive integer: ");
    num = getDouble();
  } while(num < 0);

  println("%d %s a prime number.", num, isprime(num) ? "is" : "is not");

  return 0;
}

bool isprime(int num)
{
  // If num is negative, make it positive
  if (num < 0) num = -num;
  
  // 0 is not prime
  if (num == 0) return false;

  // 1 is prime
  if (num == 1) return true;

  // check if given number is prime
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return false;
  }

  return true;
}
