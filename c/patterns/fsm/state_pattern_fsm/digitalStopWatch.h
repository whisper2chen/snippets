#ifndef __DIGITAL_STOPWATCH_H
#define __DIGITAL_STOPWATCH_H


typedef struct digitalStopWatch* digitalStopWatchPtr;

digitalStopWatchPtr createDigitalStopWatch(void);
void freeDigitalStopWatch(digitalStopWatchPtr instance);
char *digitalStopWatchStatus(digitalStopWatchPtr instance);
void startWatch(digitalStopWatchPtr instance);
void stopWatch(digitalStopWatchPtr instance);
void suspendWatch(digitalStopWatchPtr instance);
void shutdownWatch(digitalStopWatchPtr instance);
#endif
