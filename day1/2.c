//write a program to find some of numbers in a array using malloc

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0;
    int *arr;

    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("The sum of the array elements is: %d\n", sum);

    free(arr);

    return 0;
}