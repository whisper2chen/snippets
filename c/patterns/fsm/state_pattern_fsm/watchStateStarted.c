#include <stdio.h>
#include "watchStateStopped.h"
#include "watchStateStarted.h"
#include "watchStateShutdown.h"
#include "watchStateSuspend.h"


static void stopWatch(watchStatePtr state){                                
    trasitionToStopped(state);
}                                                                                
static void suspendWatch(watchStatePtr state){                                
    transitionToSuspend(state);
}                                                                                
static void shutdownWatch(watchStatePtr state){                                
    transitionToShutdown(state);
}                                                                                
void transitionToStarted(watchStatePtr state){                                          
    //printf("%s -> started\n",state->name);
    defaultEventFunc(state);                                                     
    state->name = "started";
    state->stop = stopWatch;                                                     
    state->suspend = suspendWatch;                                                     
    state->shutdown = shutdownWatch;                                                     
}    
