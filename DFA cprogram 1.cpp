#include <stdio.h>
#include <stdbool.h>

// Define the states of the DFA
enum State {
    START, // Initial state
    ACCEPT, // Accept state
    REJECT // Reject state
};
enum State runDFA(const char* input) {
    enum State currentState = START;
    int index = 0;

    while (input[index] != '\0') {
        char currentSymbol = input[index];

        switch (currentState) {
            case START:
                if (currentSymbol == 'a') {
                    currentState = ACCEPT;
                } else {
                    currentState = REJECT;
                }
                break;
            case ACCEPT:
                if (currentSymbol == 'a') {
                    currentState = ACCEPT;
                } else {
                    currentState = REJECT;
                }
                break;
            case REJECT:
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

