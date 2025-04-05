/* address_list.c */
// This program should be completed such that it maintains a list of students
// TO DO 1: DONE!!! Write a function inputStudent(int i), which allows the user
// to enter first name and last name and stores it at position i in the array.
// TO DO 2: DONE!!! Use a variable to count the number of students stored in the
// array. TO DO 3: DONE!!! Write a function printStudent(i), which prints
// student i stored in the array TO DO 4: DONE!!! Write functions addStudent(),
// for adding a student at the end of the array, and printAllStudents() for
// printing all students stored. TO DO 5: DONE!!! Write a function menu(), which
// allows the user to select one of the actions
//            - add Student
//            - print all students
//            - quit program
// TO DO 6: DONE!!! Extend the student data and the corresponding functions with
// the gender male/female (using "enum"). TO DO 7: DONE!!! Create a structure
// for handling dates (day, month, year) and use it for birth date, date of
// enrollment etc. TO DO 8: DONE!!! Extend the program such it also handles
// address information (street, number, zip-code and city). TO DO 9: DONE!!!
// optional: Add a function and menu item for deleting a selected student. TO DO
// 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef enum { MALE, FEMALE, NONE } Gender;

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct {
  char street[MAX_ADDRESS_LENGTH];
  int number;
  int zip_code;
  char city[MAX_ADDRESS_LENGTH];
} Address;

typedef struct {
  char first_name[MAX_NAME_LENGTH];
  char last_name[MAX_NAME_LENGTH];
  Gender gender;
  Date birth_date;
  Date enrollment_date;
  Address address;
} Student;

Student students[MAX_STUDENTS];

// Function to introduce a delay using time.h
void delay(int seconds) {
  int milli_seconds = 1000 * seconds;
  clock_t start_time = clock();
  while (clock() < start_time + milli_seconds);
}

// Function to clear the input buffer
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

// Function to validate date input
int isValidDate(int day, int month, int year) {
  if (year < 1 || year > 9999) return 0;
  if (month < 1 || month > 12) return 0;
  if (day < 1 || day > 31) return 0;

  // Check for months with 30 days
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) return 0;
  }

  // Check for February
  if (month == 2) {
    // Check for leap year
    int isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (day > 29 || (day == 29 && !isLeap)) return 0;
  }

  return 1;
}

// Function to add a new student to the list
void addStudent(int *numberStudents) {
  if (*numberStudents >= MAX_STUDENTS) {
    printf("Maximum number of students reached.\n");
    return;
  }

  printf("Enter first name: ");
  scanf("%s", students[*numberStudents].first_name);
  clearInputBuffer();  // Clear the input buffer after reading the first name
  printf("Enter last name: ");
  scanf("%s", students[*numberStudents].last_name);
  clearInputBuffer();  // Clear the input buffer after reading the last name

  char genderInput[10];
  while (1) {
    printf("Whats the gender of the Student? (male, female, none)\n");
    scanf("%s", genderInput);
    clearInputBuffer();  // Clear the input buffer after reading the gender

    if (strcmp(genderInput, "male") == 0) {
      students[*numberStudents].gender = MALE;
      break;
    } else if (strcmp(genderInput, "female") == 0) {
      students[*numberStudents].gender = FEMALE;
      break;
    } else if (strcmp(genderInput, "none") == 0) {
      students[*numberStudents].gender = NONE;
      break;
    } else {
      printf("Invalid input. Please enter 'male', 'female', or 'none'.\n");
    }
  }

  char dateInput[20];
  while (1) {
    printf("Enter birth date (dd mm yyyy): ");
    fgets(dateInput, sizeof(dateInput), stdin);
    if (sscanf(dateInput, "%d %d %d", &students[*numberStudents].birth_date.day,
               &students[*numberStudents].birth_date.month,
               &students[*numberStudents].birth_date.year) == 3) {
      break;
    } else {
      printf(
          "Invalid date format. Please enter the date in the format (dd mm "
          "yyyy).\n");
    }
  }

  while (1) {
    printf("Enter enrollment date (dd mm yyyy): ");
    fgets(dateInput, sizeof(dateInput), stdin);
    if (sscanf(dateInput, "%d %d %d",
               &students[*numberStudents].enrollment_date.day,
               &students[*numberStudents].enrollment_date.month,
               &students[*numberStudents].enrollment_date.year) == 3) {
      break;
    } else {
      printf(
          "Invalid date format. Please enter the date in the format (dd mm "
          "yyyy).\n");
    }
  }

  printf("Enter street: ");
  fgets(students[*numberStudents].address.street,
        sizeof(students[*numberStudents].address.street), stdin);
  students[*numberStudents]
      .address.street[strcspn(students[*numberStudents].address.street, "\n")] =
      '\0';  // Remove newline character

  printf("Enter number: ");
  scanf("%d", &students[*numberStudents].address.number);
  clearInputBuffer();  // Clear the input buffer after reading the number

  printf("Enter zip code: ");
  scanf("%d", &students[*numberStudents].address.zip_code);
  clearInputBuffer();  // Clear the input buffer after reading the zip code

  printf("Enter city: ");
  fgets(students[*numberStudents].address.city,
        sizeof(students[*numberStudents].address.city), stdin);
  students[*numberStudents]
      .address.city[strcspn(students[*numberStudents].address.city, "\n")] =
      '\0';  // Remove newline character

  printf("Total Number of Students: %2d Student(s)\n", *numberStudents + 1);
  (*numberStudents)++;
}

// Function to print a list of all students
void display(int numberStudents) {
  printf("%-4s %-15s %-15s %-10s %-10s %10s %18s %-10s %-9s %-14s\n", "No.",
         "Last Name:", "First Name:", "Gender:", "Birth Date:", "Enroll Date:",
         "Street:", "Number:", "Zip Code:", "City:");
  for (int i = 0; i < numberStudents; i++) {
    char *genderStr;
    switch (students[i].gender) {
      case MALE:
        genderStr = "male";
        break;
      case FEMALE:
        genderStr = "female";
        break;
      default:
        genderStr = "none";
        break;
    }
    printf(
        "%-4d %-15s %-15s %-10s %02d/%02d/%04d  %02d/%02d/%04d %20s %-8d %10d, "
        "%-15s\n",
        i + 1, students[i].last_name, students[i].first_name, genderStr,
        students[i].birth_date.day, students[i].birth_date.month,
        students[i].birth_date.year, students[i].enrollment_date.day,
        students[i].enrollment_date.month, students[i].enrollment_date.year,
        students[i].address.street, students[i].address.number,
        students[i].address.zip_code, students[i].address.city);
  }
  printf("End of list!!!\n\n");
  delay(1);  // Delay for 1 seconds
}

// Function to delete individual students
int deleteStudent(int *numberStudents) {
  char keyInput[100];
  display(*numberStudents);
  printf("Enter the appropriate number of the student you want to delete: \n");
  fgets(keyInput, sizeof(keyInput), stdin);  // Read the entire input line

  // Process only the first valid character of the input
  int deleteStudent = -1;
  for (int i = 0; keyInput[i] != '\0'; i++) {
    if (keyInput[i] >= '0' && keyInput[i] <= '9') {
      deleteStudent = keyInput[i] - '0';
      break;
    }
  }

  if (deleteStudent < 1 || deleteStudent > *numberStudents) {
    printf("Invalid student number.\n");
    return 0;
  }

  deleteStudent--;  // Adjust for zero-based index

  // Overwrite deleted student with data from next line until end of entries
  for (int i = deleteStudent; i < *numberStudents - 1; i++) {
    students[i] = students[i + 1];
  }

  // Decrease number of students
  (*numberStudents)--;

  // Print success status
  printf("Deleted %d. Student successfully!\n\n", deleteStudent + 1);
  return 1;
}

// Function to initialize test data
void initializeTestData(int *numberStudents) {
  if (*numberStudents + 3 > MAX_STUDENTS) {
    printf("Not enough space to add test data.\n");
    return;
  }

  strcpy(students[*numberStudents].first_name, "Max");
  strcpy(students[*numberStudents].last_name, "Mustermann");
  students[*numberStudents].gender = MALE;
  students[*numberStudents].birth_date = (Date){1, 1, 2000};
  students[*numberStudents].enrollment_date = (Date){1, 9, 2020};
  strcpy(students[*numberStudents].address.street, "Main Street");
  students[*numberStudents].address.number = 123;
  students[*numberStudents].address.zip_code = 12345;
  strcpy(students[*numberStudents].address.city, "Sample City");
  (*numberStudents)++;

  strcpy(students[*numberStudents].first_name, "Maxine");
  strcpy(students[*numberStudents].last_name, "Musterfrau");
  students[*numberStudents].gender = FEMALE;
  students[*numberStudents].birth_date = (Date){2, 2, 2001};
  students[*numberStudents].enrollment_date = (Date){1, 9, 2020};
  strcpy(students[*numberStudents].address.street, "Second Street");
  students[*numberStudents].address.number = 456;
  students[*numberStudents].address.zip_code = 67890;
  strcpy(students[*numberStudents].address.city, "Example Town");
  (*numberStudents)++;

  strcpy(students[*numberStudents].first_name, "Mäxchen");
  strcpy(students[*numberStudents].last_name, "Muster");
  students[*numberStudents].gender = MALE;
  students[*numberStudents].birth_date = (Date){3, 3, 2002};
  students[*numberStudents].enrollment_date = (Date){1, 9, 2020};
  strcpy(students[*numberStudents].address.street, "Third Avenue");
  students[*numberStudents].address.number = 789;
  students[*numberStudents].address.zip_code = 54321;
  strcpy(students[*numberStudents].address.city, "Test City");
  (*numberStudents)++;

  printf("Test data initialized.\n");
}

// Menu function to handle user input and call appropriate functions
char menu() {
  char keyInput[100];
  printf(
      "Choose what function you want to use: \n1. Add a new Student! \n2. "
      "Print all stored Students! \n3. Remove specific Student! \n9. "
      "Initialize test data! \nq. Quit the Program!\n");
  fgets(keyInput, sizeof(keyInput), stdin);  // Read the entire input line

  // Process only the first valid character of the input
  char option = '\0';
  for (int i = 0; keyInput[i] != '\0'; i++) {
    if (keyInput[i] == '1' || keyInput[i] == '2' || keyInput[i] == '3' ||
        keyInput[i] == '9' || keyInput[i] == 'q') {
      option = keyInput[i];
      break;
    }
  }

  return option;
}

int main() {
  int numberStudents = 0;

  while (1) {
    char option = menu();

    printf("\n\n\n");

    if (option == '1') {
      addStudent(&numberStudents);
    } else if (option == '2') {
      display(numberStudents);
    } else if (option == '3') {
      deleteStudent(&numberStudents);
    } else if (option == '9') {
      initializeTestData(&numberStudents);
    } else if (option == 'q') {
      break;
    } else if (option != '\0') {
      printf("Invalid input. Please try again.\n\n");
      delay(2);  // Delay for 2 seconds
    }
  }

  return 0;
}