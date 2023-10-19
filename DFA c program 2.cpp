#include <stdio.h>
#include <stdbool.h>

// Define the states of the DFA
enum State {
    START, // Initial state
    STATE_0, // State after seeing '0'
    ACCEPT, // Accept state
    REJECT // Reject state
};

// Function to simulate the DFA
enum State runDFA(const char* input) {
    enum State currentState = START;
    int index = 0;

    while (input[index] != '\0') {
        char currentSymbol = input[index];

        switch (currentState) {
            case START:
                if (currentSymbol == '0') {
                    currentState = STATE_0;
                } else {
                    currentState = REJECT;
                }
                break;
            case STATE_0:
                if (currentSymbol == '0') {
                    currentState = STATE_0;
                } else if (currentSymbol == '1') {
                    currentState = ACCEPT;
                } else {
                    currentState = REJECT;
                }
                break;
            case ACCEPT:
            case REJECT:
                // Stay in the ACCEPT or REJECT state
                break;
        }

        index++;
    }

    return currentState;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    enum State result = runDFA(input);

    if (result == ACCEPT) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}

