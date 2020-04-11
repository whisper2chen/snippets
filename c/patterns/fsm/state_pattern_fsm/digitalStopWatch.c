#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "watchState.h"
#include "watchStateStopped.h"
#include "digitalStopWatch.h"


struct digitalStopWatch {
    struct watchState state;
};


digitalStopWatchPtr createDigitalStopWatch(void){
    digitalStopWatchPtr instance = malloc(sizeof(struct digitalStopWatch));
    assert(instance != NULL);
    trasitionToStopped(&(instance->state));
    return instance;
}

void freeDigitalStopWatch(digitalStopWatchPtr instance){
    if (instance) free(instance);
}

char *digitalStopWatchStatus(digitalStopWatchPtr instance){
    return instance->state.name;
}



void startWatch(digitalStopWatchPtr instance){
    //printf("%s\n",__func__);
    instance->state.start(&(instance->state));
}


void stopWatch(digitalStopWatchPtr instance){
    //printf("%s\n",__func__);
    instance->state.stop(&(instance->state));
}

void suspendWatch(digitalStopWatchPtr instance){
    //printf("%s\n",__func__);
    instance->state.suspend(&(instance->state));
}
void shutdownWatch(digitalStopWatchPtr instance){
    //printf("%s\n",__func__);
    instance->state.shutdown(&(instance->state));
}
