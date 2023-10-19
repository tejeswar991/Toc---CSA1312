#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the states of the NFA
enum State {
    Q0, // Initial state
    Q1, // Accept state
    Q2, // Reject state
};

// Define the transition function for the NFA
enum State transition(enum State currentState, char inputSymbol) {
    switch (currentState) {
        case Q0:
            if (inputSymbol == 'o') {
                return Q1;
            }
            return Q0;
        case Q1:
            if (inputSymbol == '1') {
                return Q2;
            } else if (inputSymbol == 'o') {
                return Q1;
            }
            return Q0;
        case Q2:
            return Q2; // Stay in the reject state
    }
    return Q0; // Default case
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int index = 0;
    enum State currentState = Q0;

    while (input[index] != '\0') {
        currentState = transition(currentState, input[index]);
        index++;
    }

    if (currentState == Q1) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}

