#include <stdio.h>
#include <stdlib.h>

//Simple state machine for coffee dispenser

typedef enum
{
    STATE_IDLE,
    STATE_COIN_INSERTED,
    STATE_OPTION_SELECTED,
    STATE_COIN_RETURNED,
    MAX_STATES
} State;

typedef enum
{
    EVENT_INSERT_COIN,
    EVENT_SELECT_OPTION,
    EVENT_COFFEE_READY,
    EVENT_CANCEL,
    MAX_EVENTS
} Event;


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
    {STATE_IDLE,          NULL, idleStateHandler()},
    {STATE_COIN_INSERTED, NULL, coinInsertedHandler()}
};

//Definition of array of structures for state transitions
struct Menu_NextState nextStates[] = {
    {STATE_IDLE,          EVENT_INSERT_COIN,    STATE_COIN_INSERTED},
    {STATE_COIN_INSERTED, EVENT_SELECT_OPTION,  EVENT_CANCEL}
};

//Function for state transitions
char StateMachine(char state,char stimuli)
{
    char nextstate = state;    // Default stay in same state
    unsigned char i;
    for (i=0; menu_nextstate[i].state; i++)
    {
        if (menu_nextstate[i].state == state && menu_nextstate[i].input == stimuli)
        {
            // This is the one!
            nextstate = menu_nextstate[i].nextstate;
            break;
        }
    }
    return(nextstate);
}

int main()
{

    return 0;
}
