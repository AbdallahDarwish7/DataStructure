//
// Created by abdallahdarwesh on 3/21/19.
//

#ifndef QUEUE_HPP
#define QUEUE_HPP
struct CharNode {
    CharNode *next;
    char data;
};

struct CharQueueLL {
    CharNode *rear = nullptr; //using circulation configuration
    int size = 0;
};

void enqueue(CharQueueLL &, char );

char dequeue(CharQueueLL &);

char front(const CharQueueLL &);

bool isEmpty(const CharQueueLL &);

int size(const CharQueueLL &);

void clear(CharQueueLL &);

#endif //QUEUE_HPP
