#include <stdio.h>
#include "watchState.h"
#include "watchStateStarted.h" 
#include "watchStateShutdown.h" 
#include "watchStateSuspend.h" 

static void startWatch(watchStatePtr state){
    transitionToStarted(state);
}
static void shutdownWatch(watchStatePtr state){
    transitionToShutdown(state);
}

void transitionToSuspend(watchStatePtr state){
    //printf("%s -> suspend\n",state->name);
    defaultEventFunc(state);
    state->name     = "suspend";
    state->start    = startWatch;
    state->shutdown = shutdownWatch;
}
