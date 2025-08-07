#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int i;

    printf("Memory addresses and values of array elements:\n");
    for (i = 0; i < 5; i++) {
        printf("Address of arr[%d]: %p\t Value: %d\n", i, (void*)&arr[i], arr[i]);
    }

    int x = 100;
    printf("\nMemory address of variable x: %p\t Value: %d\n", (void*)&x, x);

    return 0;
}
