//
// Created by abdallahdarwesh on 3/21/19.
//
#include "queue.hpp"

void enqueue(CharQueueLL &queue, char data) {
    CharNode *pn = new CharNode{nullptr, data};
    if (!queue.rear) { //special case
        queue.rear = pn;
        queue.rear->next = pn;
    }
    CharNode *pTemp = queue.rear->next;
    queue.rear->next = pn;
    queue.rear = pn;
    queue.rear->next = pTemp;
    queue.size++;
}

char dequeue(CharQueueLL &queue) {

    if(queue.rear==queue.rear->next){ //special case
        char temp=queue.rear->data;
        delete queue.rear;
        queue.rear= nullptr;
        queue.size=0;
        return temp;
    }

    CharNode *pn = queue.rear->next;
    char temp = pn->data;
    queue.rear->next = queue.rear->next->next;
    delete pn;
    queue.size--;
    return temp;
}

char front(const CharQueueLL &queue) {
    return queue.rear->next->data;
}

bool isEmpty(const CharQueueLL &queue) {
    return !queue.rear;
}

int size(const CharQueueLL &queue) {
    return queue.size;
}

void clear(CharQueueLL &queue) {
    CharNode *pn = queue.rear->next;
    while (queue.rear != queue.rear->next) {
        queue.rear->next = queue.rear->next->next;
        delete pn;
        pn = queue.rear->next;
    }
    delete queue.rear;
    queue.rear = nullptr;
    queue.size = 0;
}