#include <stdio.h>
#include "watchState.h"
#include "watchStateStarted.h" 
#include "watchStateSuspend.h" 
#include "watchStateShutdown.h" 

static void startWatch(watchStatePtr state){
    transitionToStarted(state);
}

void transitionToShutdown(watchStatePtr state){
    //printf("%s -> shutdown\n",state->name);
    defaultEventFunc(state);
    state->name = "shutdown";
    state->start = startWatch;
}
