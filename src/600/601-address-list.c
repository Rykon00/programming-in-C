/* address_list.c */
// This program should be completed such that it maintains a list of students
// TO DO 1: DONE!!! Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
// TO DO 2: DONE!!! Use a variable to count the number of students stored in the array.
// TO DO 3: DONE!!! Write a function printStudent(i), which prints student i stored in the array
// TO DO 4: Write functions addStudent(), for adding a student at the end of the array, and printAllStudents() for printing all students stored.
// TO DO 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - quit program
// TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
// TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc.
// TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TO DO 9: optional: Add a function and menu item for deleting a selected student.
// TO DO 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>

struct person {
    char first_name[30];
    char last_name[30];
};
struct person students[100];
struct person new_student;

// function to add new Student
void addStudent(int numberStudents) {
    printf("Enter first Name: \n");
    char first_name[30];
    scanf("%s", new_student.first_name);
    printf("Enter last Name: \n");
    char last_name[30];
    scanf("%s", new_student.last_name);
    // Assuming you want to store it at the first position for now
    students[0] = new_student;
    printf("Student added: %s %s\n", students[numberStudents].first_name, students[numberStudents].last_name);
    printf("Total Number of Students: %2d Student\n", numberStudents + 1);
    numberStudents += 1;
}

// function to print a list of all students
void display(int numberStudents) {
    for (int i = 0; i < numberStudents; i++) {
        printf("%c, %c\n", new_student.first_name[i], new_student.last_name[i]);
    }
}

int main() {
    int numberStudents = 0;
    for (int i = 0; i < 999; i++) {
        printf("Choose what function you want to use: \n1. Add a new Student! \n2. Print all stored Students! \nq. Quit the Program!");
        
        }
}