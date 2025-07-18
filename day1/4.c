// write a program to create a struture student with details like name age subject id. access the structure members using 
// - strucuture varialbe
// - pointer varialbe

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    char subject[50];
    int id;
};

void printStudentDetails(struct Student *s) {
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("Subject: %s\n", s->subject);
    printf("ID: %d\n", s->id);
}

int main() {
    struct Student student;
    struct Student *studentPtr = &student;

    // input using structure variable
    scanf("%49s", student.name);
    scanf("%d", &student.age);
    scanf("%49s", student.subject);
    scanf("%d", &student.id);

    printf("\nStudent Details (using structure variable):\n");
    printStudentDetails(&student);

    // input using pointer variable
    scanf("%49s", studentPtr->name);
    scanf("%d", &studentPtr->age);
    scanf("%49s", studentPtr->subject);
    scanf("%d", &studentPtr->id);

    printf("\nStudent Details (using pointer variable):\n");
    printStudentDetails(studentPtr);

    return 0;
}