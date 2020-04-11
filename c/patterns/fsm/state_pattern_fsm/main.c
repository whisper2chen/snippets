#include <stdio.h>
#include <assert.h>
#include "digitalStopWatch.h"

#define assert_status(instance,status) assert(strcmp(digitalStopWatchStatus(instance),status) == 0)

int main(int argc, char *argv[])
{
    digitalStopWatchPtr instance  = createDigitalStopWatch();

    assert_status(instance, "stopped");
    startWatch(instance);
    assert_status(instance, "started");
    suspendWatch(instance);
    assert_status(instance, "suspend");
    shutdownWatch(instance); 
    assert_status(instance, "shutdown");
    startWatch(instance);
    assert_status(instance, "started");
    shutdownWatch(instance); 
    assert_status(instance, "shutdown");
    suspendWatch(instance);
    assert_status(instance, "shutdown");
    stopWatch(instance);
    assert_status(instance, "shutdown");
    shutdownWatch(instance); 
    assert_status(instance, "shutdown");
    suspendWatch(instance);
    assert_status(instance, "shutdown");
    startWatch(instance);
    assert_status(instance, "started");
    shutdownWatch(instance); 
    assert_status(instance, "shutdown");
    suspendWatch(instance);
    assert_status(instance, "shutdown");
    stopWatch(instance);
    assert_status(instance, "shutdown");
    stopWatch(instance);
    assert_status(instance, "shutdown");
    suspendWatch(instance);
    assert_status(instance, "shutdown");
    shutdownWatch(instance); 
    assert_status(instance, "shutdown");

    freeDigitalStopWatch(instance);
    return 0;
}
