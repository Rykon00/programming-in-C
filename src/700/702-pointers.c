/* pointers.c
   TO DO 1: DONE!!! Extend/modify the address_list.c program such that the student data is not stored
                    in a global but in local data structures in main.
   TO DO 2: DONE!!! Use pointers/call by reference to pass student data to the different functions.
   TO DO 3: DONE!!! use typedef to define a type for 'struct person' and use this type

   Some code snippets are given below.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

// Define struct person and use typedef
typedef struct {
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    int age;
} Person;

// Modify the print_student function
void print_student(Person *s) {
    printf("%-20s %-20s %-5d\n", s->first_name, s->last_name, s->age);
}

// Function to add a student
void add_student(Person *students, int *number_students) {
    if (*number_students >= MAX_STUDENTS) {
        printf("Cannot add more students.\n");
        return;
    }
    printf("Enter first name: ");
    scanf("%s", students[*number_students].first_name);
    printf("Enter last name: ");
    scanf("%s", students[*number_students].last_name);
    printf("Enter age: ");
    scanf("%d", &students[*number_students].age);
    (*number_students)++;
}

// Function to print all students
void print_all_students(Person *students, int number_students) {
    printf("%-20s %-20s %-5s\n", "First Name", "Last Name", "Age");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < number_students; i++) {
        print_student(&students[i]);
    }
}

// Function to delete a student
void delete_student(Person *students, int *number_students) {
    if (*number_students == 0) {
        printf("No students to delete.\n");
        return;
    }
    int index;
    printf("Enter the index of the student to delete (0 to %d): ", *number_students - 1);
    scanf("%d", &index);
    if (index < 0 || index >= *number_students) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < *number_students - 1; i++) {
        students[i] = students[i + 1];
    }
    (*number_students)--;
}

// Function to sort students by first name
int compare_by_first_name(const void *a, const void *b) {
    return strcmp(((Person *)a)->first_name, ((Person *)b)->first_name);
}

void sort_students(Person *students, int number_students) {
    qsort(students, number_students, sizeof(Person), compare_by_first_name);
}

// Function to import test data
void import_test_data(Person *students, int *number_students) {
    strcpy(students[*number_students].first_name, "John");
    strcpy(students[*number_students].last_name, "Doe");
    students[*number_students].age = 20;
    (*number_students)++;

    strcpy(students[*number_students].first_name, "Jane");
    strcpy(students[*number_students].last_name, "Smith");
    students[*number_students].age = 22;
    (*number_students)++;

    strcpy(students[*number_students].first_name, "Alice");
    strcpy(students[*number_students].last_name, "Johnson");
    students[*number_students].age = 19;
    (*number_students)++;
}

// Function to display the menu and get the user's choice
char menu() {
    char choice;
    printf("\nMenu:\n");
    printf("1. Add Student\n");
    printf("2. Print All Students\n");
    printf("3. Delete Student\n");
    printf("4. Sort Students by First Name\n");
    printf("5. Import Test Data\n");
    printf("q. Quit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    return choice;
}

int main() {
    Person students[MAX_STUDENTS];
    int number_students = 0;
    char choice;

    while ((choice = menu()) != 'q') {
        switch (choice) {
        case '1':
            add_student(students, &number_students);
            break;
        case '2':
            print_all_students(students, number_students);
            break;
        case '3':
            delete_student(students, &number_students);
            break;
        case '4':
            sort_students(students, number_students);
            break;
        case '5':
            import_test_data(students, &number_students);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}
