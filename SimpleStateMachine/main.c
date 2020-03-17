#include <stdio.h>
#include <stdlib.h>

//Simple state machine for coffee dispenser

typedef enum
{
    STATE_IDLE,
    STATE_COIN_INSERTED,
    STATE_OPTION_SELECTED,
    STATE_COIN_RETURNED,
    STATE_ERROR
} State;

typedef enum
{
    EVENT_INSERT_COIN,
    EVENT_SELECT_OPTION,
    EVENT_COFFEE_READY,
    EVENT_CANCEL,
    MAX_EVENTS
} Event;


State currentState = STATE_IDLE;

//State handlers
char idleStateHandler()
{
    return 0;
}

char coinInsertedHandler()
{
    return 1;
}

//Structure that codes state transitions.
struct Menu_NextState
{
    unsigned int state;
    unsigned int event;
    unsigned int nextState;
};

//Structure that codes state function handlers.
struct Menu_State
{
    unsigned int state;
    char *pText;
    char (*pHandler)(void);
};

//Definition of array of menu state structures
struct Menu_State menuStates[] = {
    {STATE_IDLE,          NULL, idleStateHandler},
    {STATE_COIN_INSERTED, NULL, coinInsertedHandler}
};

//Definition of array of structures for state transitions
struct Menu_NextState nextStates[] = {
    {STATE_IDLE,            EVENT_INSERT_COIN,    STATE_COIN_INSERTED},
    {STATE_IDLE,            EVENT_CANCEL,         STATE_IDLE},
    {STATE_COIN_INSERTED,   EVENT_SELECT_OPTION,  STATE_OPTION_SELECTED},
    {STATE_COIN_INSERTED,   EVENT_CANCEL,         STATE_IDLE},
    {STATE_OPTION_SELECTED, EVENT_COFFEE_READY,   STATE_IDLE},
};

//Function for state transitions.
unsigned int StateMachine(unsigned int state, unsigned int stimuli)
{
    unsigned int nextState = state;    // Default stay in same state
    unsigned int i;
    unsigned int numberOfStates = 2;
    for (i=0; i<numberOfStates; i++)
    {
        if (nextStates[i].state == state && nextStates[i].event == stimuli)
        {
            // This is the one!
            nextState = nextStates[i].nextState;
            break;
        }
        nextState = STATE_ERROR;
    }
    return(nextState);
}

int main()
{
    unsigned int testStimuli = 0;
    unsigned int newState = STATE_IDLE;
    char stimuli;
    //ubaciti scanf
    newState = StateMachine(currentState, testStimuli);
    currentState = newState;
    printf("%d\n", newState);
    return 0;
}
