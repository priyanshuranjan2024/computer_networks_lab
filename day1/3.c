//write a program to demonstrate the structure and access there members by creating a structure to hold student details like name roll state and age.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
    char state[50];
    int age;
};

void printStudentDetails(struct Student *s) {
    printf("Name: %s\n", s->name);
    printf("Roll: %d\n", s->roll);
    printf("State: %s\n", s->state);
    printf("Age: %d\n", s->age);
}

int main() {
    struct Student *student = (struct Student *)malloc(sizeof(struct Student));

    printf("Enter student name: ");
    scanf("%49s", student->name);
    printf("Enter student roll number: ");
    scanf("%d", &student->roll);
    printf("Enter student state: ");
    scanf("%49s", student->state);
    printf("Enter student age: ");
    scanf("%d", &student->age);
    printf("\nStudent Details:\n");
    printStudentDetails(student);
    free(student);

    return 0;
}