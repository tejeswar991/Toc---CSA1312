#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10
#define MAX_TRANSITIONS 10

// Structure to represent an NFA transition
struct NFATransition {
    int nextState;
    char transitionSymbol;
};

// Structure to represent an NFA state
struct NFAState {
    int stateNumber;
    struct NFATransition transitions[MAX_TRANSITIONS];
    int numTransitions;
};

// Function to add a transition to an NFA state
void addTransition(struct NFAState* state, int nextState, char transitionSymbol) {
    state->transitions[state->numTransitions].nextState = nextState;
    state->transitions[state->numTransitions].transitionSymbol = transitionSymbol;
    state->numTransitions++;
}

// Function to calculate the e-closure of a state
void epsilonClosure(struct NFAState states[], int currentState, bool visited[]) {
    visited[currentState] = true;
    
    for (int i = 0; i < states[currentState].numTransitions; i++) {
        if (states[currentState].transitions[i].transitionSymbol == 'e') {
            int nextState = states[currentState].transitions[i].nextState;
            if (!visited[nextState]) {
                epsilonClosure(states, nextState, visited);
            }
        }
    }
}

int main() {
    int numStates, numTransitions;
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &numStates);
    printf("Enter the number of transitions in the NFA: ");
    scanf("%d", &numTransitions);

    struct NFAState states[MAX_STATES];

    // Initialize NFA states
    for (int i = 0; i < numStates; i++) {
        states[i].stateNumber = i;
        states[i].numTransitions = 0;
    }

    // Read transitions
    for (int i = 0; i < numTransitions; i++) 
        int fromState, toState;
        char transitionSymbol;
        printf("Enter transition (from to symbol): ");
        scanf("%d %d %c", & fromState, &toState, &transitionSymbol);
        addTransition(&states[fromState], toState, transitionSymbol);
    }

    //

