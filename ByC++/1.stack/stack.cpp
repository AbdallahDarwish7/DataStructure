//
// Created by abdallahdarwesh on 3/21/19.
//

#include "stack.hpp"

#ifdef ARRAY_BASED
void push(CharsStackArray &stack, char data){
    stack.arr[++stack.top]=data;
}

char pop(CharsStackArray &stack){
    return stack.arr[stack.top--];
}

char front(CharsStackArray &stack){
    return stack.arr[stack.top];
}
bool isEmpty(CharsStackArray &stack){
    return stack.top==-1;
}
int size( CharsStackArray &stack ){
    return stack.top+1;
}
void clear( CharsStackArray &stack ){
    stack.top=-1;
}
#else

void push(CharStackLL &stack, char data) {
    CharNode *pn = new CharNode{nullptr, data};
    pn->next = stack.ps;
    stack.ps = pn;
    stack.size++;
}

char pop(CharStackLL &stack) {
    CharNode *pn = stack.ps;
    char temp = pn->data;
    stack.ps = stack.ps->next;
    delete pn;
    stack.size--;
    return temp;
}

char front(const CharStackLL &stack) {
    return stack.ps->data;
}

bool isEmpty(const CharStackLL &stack) {
    return !(stack.ps);
}

int size(const CharStackLL &stack) {
    return stack.size;
}

void clear(CharStackLL &stack) {
    CharNode *pn=stack.ps;
    while(stack.ps){
        stack.ps=stack.ps->next;
        delete pn;
        pn=stack.ps;
    }
    stack.size=0;
}

#endif