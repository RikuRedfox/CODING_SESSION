#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char gradeLetter;
  uint8_t min;
  uint8_t max;
} Grade;

uint8_t grade_input(uint8_t *grade) {
  int result;

  do {
    printf("Enter your grade: ");
    result = scanf("%" SCNu8, grade);
    if (result != 1) {
      printf("Invalid input. Please enter a number between 0 to 100.\n");
      while ((getchar()) != '\n') {
      };
      clearerr(stdin);
    }
  } while (result != 1 || *grade > 100);

  return *grade;
}

int main(void) {
  Grade gradingSystem[] = {
      {'A', 90, 100}, {'B', 80, 89}, {'C', 75, 79}, {'F', 0, 74}};
  printf("Size of Grade: %llu \nSize of Grading System: %llu\n", sizeof(Grade),
         sizeof(gradingSystem));

  uint8_t grade;
  grade_input(&grade);

  for (uint8_t i = 0; i < sizeof(gradingSystem) / sizeof(Grade); i++) {
    if (grade >= gradingSystem[i].min && grade <= gradingSystem[i].max) {
      printf("Your Letter grade is %c have a grade of %" PRIu8 "\n",
             gradingSystem[i].gradeLetter, grade);
    } else if (i == sizeof(gradingSystem) / sizeof(Grade) - 1 &&
               grade <= gradingSystem[i].max) {
      printf("You failed your subject.");
    }
  }

  return EXIT_SUCCESS;
}

// Typical shinanegans
// char letterGrade = (grade >= 90 && grade <= 100)  ? 'A'
//                    : (grade >= 80 && grade <= 89) ? 'B'
//                    : (grade >= 75 && grade <= 79) ? 'C'
//                                                   : 'F';

// switch (letterGrade) {
// case 'A':
// case 'B':
// case 'C':
//   printf("Your letter grade is %c have a grade of %hu.", letterGrade, grade);
//   break;
// default:
//   printf("You failed your subject.");
// }