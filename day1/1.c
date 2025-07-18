// write a program to demontrate call by value and call by reference
#include<stdio.h>

void callByValue(int a, int b) {
    a = a + 10;
    b = b + 10;
    printf("Inside callByValue: a = %d, b = %d\n", a, b);
}

void callByReference(int *a, int *b) {
    *a = *a + 10;
    *b = *b + 10;
    printf("Inside callByReference: a = %d, b = %d\n", *a, *b);
}

int main(){
    int x = 5, y = 10;
    printf("Before callByValue: x = %d, y = %d\n", x, y);
    callByValue(x, y);
    printf("After callByValue: x = %d, y = %d\n", x, y);
    
    printf("Before callByReference: x = %d, y = %d\n", x, y);
    callByReference(&x, &y);
    printf("After callByReference: x = %d, y = %d\n", x, y);


    return 0;
}