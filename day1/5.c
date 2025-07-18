// write a program to display the details of a structure person. age and name using dynamic memory allocation.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person {
    char name[50];
    int age;
};


void displayPersonDetails(struct Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}

int main() {
    struct Person *person = (struct Person *)malloc(sizeof(struct Person));

    scanf("%49s", person->name);
    scanf("%d", &person->age);

    printf("\nPerson Details:\n");
    displayPersonDetails(person);

    free(person);
    
    return 0;
}