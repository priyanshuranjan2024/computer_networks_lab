#include <stdio.h>
#include <string.h>

void bitStuffing(char *input, char *output) {
    int i, j = 0, count = 0;
    for (i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];
        if (input[i] == '1') {
            count++;
            if (count == 5) {
                output[j++] = '0';  // Stuff a '0'
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    output[j] = '\0';
}

int main() {
    char input[100], output[150];
    printf("Enter the binary string: ");
    scanf("%s", input);

    bitStuffing(input, output);
    printf("After bit stuffing: %s\n", output);

    return 0;
}
