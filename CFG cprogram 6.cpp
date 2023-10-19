#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to parse S according to the CFG rules
bool parseS(const char* input, int* index) {
    int originalIndex = *index;

    if (input[*index] == '0') {
        (*index)++;
        if (parseS(input, index) && input[*index] == '1') {
            (*index)++;
            return true;
        }
    }

    *index = originalIndex; // Reset index to the original position

    return true; // e production
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int index = 0;
    if (parseS(input, &index) && input[index] == '\0') {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}

