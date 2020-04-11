#ifndef __DIGITAL_STOPWATCH_H
#define __DIGITAL_STOPWATCH_H

#define STATES \
    X(stopped,"stopped")\
    X(started,"started")\
    X(suspend,"suspend")\
    X(shutdown,"shutdown")

typedef enum {
#define X(n,...) n,
    STATES
#undef X
} State;


typedef struct digitalStopWatch* digitalStopWatchPtr;

digitalStopWatchPtr createDigitalStopWatch(void);
void freeDigitalStopWatch(digitalStopWatchPtr instance);
State digitalStopWatchStatus(digitalStopWatchPtr instance);
void startWatch(digitalStopWatchPtr instance);
void stopWatch(digitalStopWatchPtr instance);
void suspendWatch(digitalStopWatchPtr instance);
void shutdownWatch(digitalStopWatchPtr instance);
#endif
