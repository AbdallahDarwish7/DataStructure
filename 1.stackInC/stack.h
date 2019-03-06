//
// Created by abdallahdrwesh on 06/03/19.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define ARRAY_BASED
#undef LINKED_BASED
#include <stdbool.h>

#define MAXSTACK 20
typedef int StackEntery;

#ifdef ARRAY_BASED
//array based
typedef struct {
    int top;
    StackEntery entery[MAXSTACK];
} Stack;
#else
//linked based
typedef struct stacknode {
    StackEntery entery;
    struct stacknode *pnext;
} StackNode;

typedef struct {
    StackNode *top;
    int size;//needed for method stackSize()
} Stack;
#endif

void intializeStack(Stack *);

void push(int, Stack *);


bool stackFull(Stack *);

StackEntery pop(Stack *);

bool stackEmpty(Stack *);

StackEntery stackTop(Stack *);

int stackSize(Stack *);

void clearStack(Stack *);

void println(StackEntery);

void traverseStack(Stack *, void(*)(StackEntery));

#endif //STACK_STACK_H
