#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *name = malloc(100 * sizeof(char));
  uint16_t answer;

  if (name == NULL) { // Check if memory allocation was successful
    printf("Memory allocation failed\n");
    return EXIT_SUCCESS;
  }

  do {
    printf("Please insert your name: ");
    scanf("%s", name);
    printf("Hello Mr/Ms. %s\n", name);
    getchar();

    printf("Would you like to change your name? [insert 1 for 'yes' and 2 for "
           "'no']: ");
    scanf("%hu", &answer);
  } while (answer == 1);

  free(name);

  return EXIT_SUCCESS;
}