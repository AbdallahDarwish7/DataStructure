//
// Created by abdallahdrwesh on 06/03/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#ifdef ARRAY_BASED
void intializeStack(Stack *ps) {
    ps->top = -1;
}

void push(int item, Stack *ps) {
    ps->top++;
    ps->entery[ps->top] = item;
}

bool stackFull(Stack *ps) {
    if (ps->top >= MAXSTACK)
        return true;
    return false;
    //return ps->top>=MAXSTACK;
}

StackEntery pop(Stack *ps) {
    return ps->entery[ps->top--];
}

bool stackEmpty(Stack *ps) {
    if (ps->top <= -1)
        return true;
    return false;
}

StackEntery stackTop(Stack *ps) {
    return ps->entery[ps->top];
}

int stackSize(Stack *ps) {
    return ++ps->top;
}

void clearStack(Stack *ps) {
    ps->top = -1;
}

void println(StackEntery item){
    printf("%d\n",item);
}

void traverseStack(Stack*ps,void(*pf)(StackEntery)){
    for (int i = ps->top; i <=0 ; --i) {
        (*pf)(ps->entery[i]);
    }
}
#else

void intializeStack(Stack *ps) {
    ps->top = NULL;
    ps->size=0;
}

void push(StackEntery item, Stack *ps) {
    StackNode *pn = (StackNode *) malloc(sizeof(StackNode));
    pn->pnext = ps->top;
    pn->entery = item;
    ps->top = pn;
    ps->size+=1;
}

bool stackFull(Stack *ps) {
    return true;
}

StackEntery pop(Stack *ps) {
    StackNode *pn = ps->top;//to save the address when we need to deallocate
    StackEntery var = ps->top->entery;
    ps->top = ps->top->pnext;
    ps->size-=1;
    free(pn);
    return var;
}

bool stackEmpty(Stack *ps) {
    if (ps->top == NULL)
        return true;
    return false;
}

void clearStack(Stack *ps) {
    StackNode *pn = ps->top, *qn = ps->top;
    while (pn != NULL) {
        free(qn);
        pn = pn->pnext;
        qn = pn;
    }
    ps->size=0;
    ps->top = NULL;
}

int stackSize(Stack *ps){
//    int count=0;
//    StackNode*pn=ps->top;
//    while(pn!=NULL){
//        count++;
//        pn=pn->pnext;
//    }
//    return count;
/* we add the filed size in stack to enhancement the complexity of algorithm above O(n)*/
/*there is a trade-off between time and space*/
    return ps->size;
}


void println(StackEntery item){
    printf("%d",item);
}


void traverseStack(Stack *ps, void(*pf)(StackEntery)){
    StackNode *pn=ps->top;
    while (pn!=NULL){
        (*pf)(pn->entery);
        pn=pn->pnext;
    }
}


#endif
