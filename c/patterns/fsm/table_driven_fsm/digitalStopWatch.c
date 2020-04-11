#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "digitalStopWatch.h"

const char*state_str[] = {
#define X(n,str) [n] = str,
    STATES
#undef X
};

#define STATE_STR(n) (state_str[(n)])

#define NUM_OF_STATES 4
#define NUM_OF_EVENTS 4
static State trasitionTable[NUM_OF_STATES][NUM_OF_EVENTS] = {
    {stopped,started,stopped,shutdown},
    {stopped,started,suspend,shutdown},
    {stopped,started,suspend,shutdown},
    {shutdown,started,shutdown,shutdown},
};

struct digitalStopWatch {
    State state;
};

void startWatch(digitalStopWatchPtr instance){
    State curState = instance->state;
    instance->state = trasitionTable[instance->state][started];
    printf("%16s %10s -> %10s\n",__func__,STATE_STR(curState),STATE_STR(instance->state));
}
void stopWatch(digitalStopWatchPtr instance){
    State curState = instance->state;
    instance->state = trasitionTable[instance->state][stopped];
    printf("%16s %10s -> %10s\n",__func__,STATE_STR(curState),STATE_STR(instance->state));
}
void suspendWatch(digitalStopWatchPtr instance){
    State curState = instance->state;
    instance->state = trasitionTable[instance->state][suspend];
    printf("%16s %10s -> %10s\n",__func__,STATE_STR(curState),STATE_STR(instance->state));
}
void shutdownWatch(digitalStopWatchPtr instance){
    State curState = instance->state;
    instance->state = trasitionTable[instance->state][shutdown];
    printf("%16s %10s -> %10s\n",__func__,STATE_STR(curState),STATE_STR(instance->state));
}

digitalStopWatchPtr createDigitalStopWatch(void){
    digitalStopWatchPtr instance = malloc(sizeof(struct digitalStopWatch));
    assert(instance != NULL);
    //initial
    instance->state = stopped;
    return instance;
}

void freeDigitalStopWatch(digitalStopWatchPtr instance){
    if (instance) free(instance);
}

State digitalStopWatchStatus(digitalStopWatchPtr instance){
    return instance->state;
}
