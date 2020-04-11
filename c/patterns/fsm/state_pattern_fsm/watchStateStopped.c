#include <stdio.h>
#include "watchStateStopped.h"
#include "watchStateShutdown.h"
#include "watchStateStarted.h"


static void startWatch(watchStatePtr state){
    transitionToStarted(state);
}
static void shutdownWatch(watchStatePtr state){
    transitionToShutdown(state);
}
void trasitionToStopped(watchStatePtr state){
    //printf("%s -> stopped\n",state->name);
    defaultEventFunc(state);
    state->name = "stopped";
    state->start = startWatch;
    state->shutdown = shutdownWatch;
}
