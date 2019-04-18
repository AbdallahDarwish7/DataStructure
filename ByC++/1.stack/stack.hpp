//
// Created by abdallahdarwesh on 3/21/19.
//

#ifndef STACK_HPP
#define STACK_HPP
//#define  ARRAY_BASED
#ifdef ARRAY_BASED

#define STACK_SIZE 100
struct CharsStackArray {
    char arr[STACK_SIZE];
    int top=-1;
};

void push(CharsStackArray &, char);

char pop(CharsStackArray &);

char front(const CharsStackArray &);

bool isEmpty(const CharsStackArray &);

int size(const CharsStackArray &);

void clear(CharsStackArray &);

#else
struct CharNode {
    CharNode *next;
    char data;
};

struct CharStackLL {
    CharNode *ps= nullptr;
    int size=0;

};

void push(CharStackLL &, char);

char pop(CharStackLL &);

char front(const CharStackLL &);

bool isEmpty(const CharStackLL &);

int size(const CharStackLL &);

void clear(CharStackLL &);


#endif


#endif //STACK_HPP
