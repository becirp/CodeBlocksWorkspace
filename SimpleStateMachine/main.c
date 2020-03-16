#include <stdio.h>
#include <stdlib.h>

//Simple state machine for coffee dispenser

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

struct Menu_State menuStates[] = {
    {STATE_IDLE,          NULL, idleStateHandler()},
    {STATE_COIN_INSERTED, NULL, coinInsertedHandler()}
};

//typedef enum
//{
//    STATE_IDLE,
//    STATE_COIN_INSERTED,
//    STATE_OPTION_SELECTED,
//    STATE_COIN_RETURNED,
//    MAX_STATES
//} State;
//
//typedef enum
//{
//    EVENT_INSERT_COIN,
//    EVENT_SELECT_OPTION,
//    EVENT_COFFEE_READY,
//    EVENT_CANCEL,
//    MAX_EVENTS
//} Event;



int main()
{

    return 0;
}
