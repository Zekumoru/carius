#include <stdio.h>

int main()
{
  const int ASCII_EXTENDED_COUNT = 255;
  const int itemsPerPage = 20;
  const int totalPages = 255 / itemsPerPage + 1;

  printf("Char\tDec\tOct\tHex\n");
  for (int ch = 0; ch <= ASCII_EXTENDED_COUNT; ch++) {
    printf("%c\t%d\t%o\t%X\n", (char)ch, ch, ch, ch);

    // pagination every 20 items
    if ((ch != 0 && ch % itemsPerPage == 0) || ch == ASCII_EXTENDED_COUNT) {
      const int currentPage = (ch == ASCII_EXTENDED_COUNT)? totalPages : ch / itemsPerPage; 
      printf("Page %d/%d\n", currentPage, totalPages);

      if (ch != ASCII_EXTENDED_COUNT) {
        printf("Press 'Enter' to load next page...\n");
        char _;
        while ((_ = getchar()) != '\n' && ch != EOF);
      }
    }
  }

  return 0;
}
