#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_USN_LENGTH 12

struct AMAStudent {
  int usn;
  char name[MAX_NAME_LENGTH];
};

bool isNumeric(const char *str) {
  for (int i = 0; str[i] != '0'; i++) {
    if (str[i] < '0' || str[i] > '9')
      return false;
  }

  return true;
}

int binarySearch(const struct AMAStudent *studentList, int length,
                 const char *value, int searchByUSN) {
  int low = 0;
  int high = length - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    const struct AMAStudent *student = &studentList[mid];

    if (searchByUSN) {
      if (student->usn == atoi(value))
        return mid;
      else if (student->usn > atoi(value))
        high = mid - 1;
      else
        low = mid + 1;
    } else {
      int nameComparison = strcmp(student->name, value);
      if (nameComparison == 0)
        return mid;
      else if (nameComparison > 0)
        high = mid - 1;
      else
        low = mid + 1;
    }
  }

  return -1;
}

void printResult(int result) {
  (result != -1) ? printf("Element is present at index %d.\n", result)
                 : printf("Element is not present in the array.\n");
}

void sortStudentsByName(struct AMAStudent *studentList, int length) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (strcmp(studentList[j].name, studentList[j + 1].name) > 0) {
        struct AMAStudent temp = studentList[j];
        studentList[j] = studentList[j + 1];
        studentList[j + 1] = temp;
      }
    }
  }
}

void sortStudentsByUSN(struct AMAStudent *studentList, int length) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (studentList[j].usn > studentList[j + 1].usn) {
        struct AMAStudent temp = studentList[j + 1];
        studentList[j] = studentList[j + 1];
        studentList[j + 1] = temp;
      }
    }
  }
}

void strToUpper(char *str) {
  for (int i = 0; str[i] != '\0'; i++)
    str[i] = toupper(str[i]);
}

int main(void) {
  struct AMAStudent studentInfo[100];
  int numStudents = 0;
  int result;

  while (true) {
    printf("[1] Add Student.\n");
    printf("[2] Search by name.\n");
    printf("[3] Search by USN.\n");
    printf("[4] Print the current list.\n");
    printf("[5] Exit.\n");

    printf("Input: ");
    int userChoose;
    if (scanf("%d", &userChoose) != 1) {
      return 1;
    }

    switch (userChoose) {
    case 1: // Add
      while (true) {
        printf("Enter Student name: ");
        char name[MAX_NAME_LENGTH];

        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        strToUpper(name);

        if (strlen(name) == 0 || strlen(name) > MAX_NAME_LENGTH)
          continue;

        char temp[MAX_USN_LENGTH];
        int usn;
        do {
          printf("Enter the student USN: ");
          fgets(temp, sizeof(temp), stdin);
          temp[strcspn(temp, "\n")] = '\0';
        } while (!isNumeric(temp) || strlen(temp) != 11);
        sscanf(temp, "%d", &usn);

        studentInfo[numStudents].usn = usn;
        strncpy(studentInfo[numStudents].name, name,
                sizeof(studentInfo[numStudents].name));

        studentInfo[numStudents]
            .name[sizeof(studentInfo[numStudents].name) - 1] = '\0';
        numStudents++;

        printf("Want to add more name? [Y/N] \n>> ");
        char userChoice[3];
        // fgets(userChoice, sizeof(userChoice), stdin);
        scanf("%2s", userChoice);
        strToUpper(userChoice);
        if (strcmp(userChoice, "Y") != 0 || strcmp(userChoice, "YES") != 0)
          break;
        else
          continue;
      }

      break;
    case 2: // Search by name
      printf("Search by name: ");

      char nameValue[100];
      scanf("%[^\n]", nameValue);

      sortStudentsByName(studentInfo, numStudents);
      result = binarySearch(studentInfo, numStudents, nameValue, 0);

      printResult(result);

      break;
    case 3: // Search by USN
      printf("Search by USN: ");
      char usnValue[11];
      scanf("%10s", usnValue);

      sortStudentsByUSN(studentInfo, numStudents);
      result = binarySearch(studentInfo, numStudents, usnValue, 1);

      printResult(result);

      break;
    case 4: // Print
      for (int i = 0; i < numStudents; i++) {
        printf("USN: %d, Name: %s\n", studentInfo[i].usn, studentInfo[i].name);
      }

      break;
    case 5:
      return 0;
    default:
      return 1;
    }
  }

  return 0;
}