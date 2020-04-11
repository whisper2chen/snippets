#ifndef __WATCHSTATE_H
#define __WATCHSTATE_H

typedef struct watchState* watchStatePtr;


typedef void (*eventStartFunc)(watchStatePtr);
typedef void (*eventStopFunc)(watchStatePtr);

struct watchState {
    char *name;
    eventStartFunc start;
    eventStopFunc stop;
    eventStopFunc suspend;
    eventStopFunc shutdown;
};
void defaultEventFunc(watchStatePtr state);
#endif
