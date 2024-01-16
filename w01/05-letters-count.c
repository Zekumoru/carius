#include <stdio.h>
#include <ctype.h>

int main()
{
  int nVowels;      // vowels count
  int nConsonants;  // consonants count
  int nOthers;      // others count
  char ch;

  printf("Enter string: ");
  while ((ch = getchar()) != '\n' && ch != '\r') {
    ch = toupper(ch);

    switch (ch) {
      case 'A':
      case 'I':
      case 'U':
      case 'E':
      case 'O': nVowels++;
      default:
        if (ch >= 'A' && ch <= 'Z') {
          nConsonants++;
        } else {
          nOthers++;
        }
    }
  }

  printf("\n");
  printf("Total vowels: %d\n", nVowels);
  printf("Total consonants: %d\n", nConsonants);
  printf("Total others: %d\n", nOthers);

  return 0;
}
