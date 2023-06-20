#include <stdlib.h>

//
// Created by leeyu on 2023/6/20.
//
typedef struct {
    int *call_history;
    int size;
    int head;
    int tail;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter *rCounter = malloc(sizeof(RecentCounter));
    rCounter->head = 0;
    rCounter->tail = 0;
    rCounter->size = 4;
    rCounter->call_history = malloc(rCounter->size * sizeof(int));
    return rCounter;
}

int recentCounterPing(RecentCounter* obj, int t) {

    if (obj->tail == obj->size) {
        int more_size = 2 * obj->size;
        obj->call_history = realloc(obj->call_history, more_size * sizeof(int));
        if (obj->call_history == NULL) return -1;
        obj->size = more_size;
    }

    obj->call_history[obj->tail++] = t;
    while (obj->call_history[obj->head] < t - 3000) {
        obj->head++;
    }

    return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter* obj) {
    if (obj == NULL) return;
    free(obj->call_history);
    free(obj);
}


int main () {
    RecentCounter* obj = recentCounterCreate();
    int param_1 = recentCounterPing(obj, t);

    recentCounterFree(obj);
}
