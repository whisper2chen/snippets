#include <stdio.h>
#include "watchState.h"


static void defaultEventStart(watchStatePtr state){
    //printf("%s :unsupported event start\n",state->name);
    return;
}
static void defaultEventStop(watchStatePtr state){
    //printf("%s :unsupported event stop\n",state->name);
    return;
}
static void defaultEventSuspend(watchStatePtr state){
    //printf("%s :unsupported event suspend\n",state->name);
    return;
}
static void defaultEventShutdown(watchStatePtr state){
    //printf("%s :unsupported event shutdown\n",state->name);
    return;
}

void defaultEventFunc(watchStatePtr state)
{
    state->start    = defaultEventStart;
    state->stop     = defaultEventStop;
    state->suspend  = defaultEventSuspend;
    state->shutdown = defaultEventShutdown;
    return;
}
