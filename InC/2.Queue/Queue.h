//
// Created by abdallahdarwesh on 3/19/19.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define  ARRAY_BASED
//#define  LINKED_BASED
typedef int QueueEntry;
#ifdef ARRAY_BASED  //circular implementation

#define MAX_QUEUE 100

typedef struct {
    int front;    //at definition these are default values
    int rear;
    int size;
    QueueEntry entry[MAX_QUEUE];
} Queue;

bool fullQueue(Queue *pq);

#else
typedef struct queuenode {
    QueueEntry entry;
    struct queuenode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

#endif // ARRAY_BASED

void intialQueue(Queue *pq);

void append(QueueEntry item, Queue *pq);

QueueEntry serve(Queue *pq);

bool emptyQueue(Queue *pq);

void clearQueue(Queue *pq);

void traverseQueue(Queue *pq, void (*)(QueueEntry));

//for ex this is the function
void print(QueueEntry);

#endif //QUEUE_H
