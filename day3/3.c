#include <stdio.h>
#include <string.h>

#define FLAG 'F'
#define ESC 'E'

void byteStuffing(char *input, char *output) {
    int i, j = 0;
    output[j++] = FLAG; // Starting flag

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == FLAG || input[i] == ESC) {
            output[j++] = ESC;
        }
        output[j++] = input[i];
    }

    output[j++] = FLAG; // Ending flag
    output[j] = '\0';
}

int main() {
    char input[100], output[200];
    printf("Enter data string (no spaces): ");
    scanf("%s", input);

    byteStuffing(input, output);
    printf("After byte stuffing: %s\n", output);

    return 0;
}
