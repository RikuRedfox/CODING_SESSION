#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char atmPin[6];

  for (uint16_t count = 0; count < 5; count++) {
    printf("Enter the PIN: ");
    scanf("%s", atmPin);
    if (strcmp(atmPin, "246810") != 1) {
      printf("You entered: %s", atmPin);
      continue;
    } else {
      puts("Correct!");
      printf("You entered: %s", atmPin);
      break;
    }
  }

  return 0;
}