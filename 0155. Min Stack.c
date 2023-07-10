#include <stdlib.h>
#include <printf.h>

//
// Created by leeyu on 2023/7/9.
//
typedef struct {
    int *stack;
    int *min;
} Pare;

typedef struct {
    //Methods pop, top and getMin operations will always be called on non-empty stacks.
    Pare *pareStack;
    int top;
    int size;
} MinStack;

void errHandler() {
    // Suppose it doesn't happen.
}

MinStack* minStackCreate() {
    int size = 4;
    MinStack *minStack = (MinStack*)malloc(sizeof(MinStack));
    minStack->pareStack = (Pare*) malloc(sizeof(Pare));
    minStack->pareStack->stack = calloc(size, sizeof(int));
    minStack->pareStack->min = calloc(size, sizeof(int));
    minStack->size = size;
    minStack->top = -1;
    return minStack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top >= obj->size - 1) {  // need more size
        obj->pareStack->stack = realloc(obj->pareStack->stack, sizeof(int) * obj->size * 2);
        obj->pareStack->min = realloc(obj->pareStack->min, sizeof(int) * obj->size * 2);
        if (obj->pareStack->stack == NULL || obj->pareStack->min == NULL) errHandler();
        obj->size *= 2;
    }

    obj->top += 1;
    obj->pareStack->stack[obj->top] = val;
    if (obj->top == 0) {  // stack empty
        obj->pareStack->min[obj->top] = val;
    } else {
        if (obj->pareStack->min[obj->top - 1] > val) {
            obj->pareStack->min[obj->top] = val;
        } else {
            obj->pareStack->min[obj->top] = obj->pareStack->min[obj->top - 1];
        }
    }

}

void minStackPop(MinStack* obj) {
    obj->top -= 1;
}

int minStackTop(MinStack* obj) {
    return obj->pareStack->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->pareStack->min[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->pareStack->stack);
    free(obj->pareStack->min);
    free(obj->pareStack);
    free(obj);
}



int main() {
    MinStack* obj = minStackCreate();
    minStackPush(obj,  -10);
    minStackPush(obj,  14);
    int p3 = minStackGetMin(obj);
    int p4 = minStackGetMin(obj);
    minStackPush(obj,  -20);
    int p6 = minStackGetMin(obj);
    int p7 = minStackGetMin(obj);
    int p8 = minStackTop(obj);
    int p9 = minStackGetMin(obj);
    minStackPop(obj);
    minStackPush(obj,  10);
    minStackPush(obj,  -7);
    int p13 = minStackGetMin(obj);
    minStackPush(obj,  -7);
    minStackPop(obj);
    int p16 = minStackTop(obj);
    int p17 = minStackGetMin(obj);
    minStackPop(obj);

    minStackFree(obj);
}

