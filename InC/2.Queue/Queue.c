//
// Created by abdallahdarwesh on 3/19/19.
//

#include "Queue.h"
#include <stdio.h>

#ifdef ARRAY_BASED

void intialQueue(Queue *pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void append(QueueEntry item, Queue *pq) {
    //   if(pq->rear==MAX_QUEUE-1)
    //       pq->entry[0]=item;
    //
    //   pq->entry[pq->rear++]=item;
    //   pq->size++;
    pq->rear = (pq->rear + 1) % MAX_QUEUE;
    pq->entry[pq->rear] = item;
    pq->size++;
}

QueueEntry serve(Queue *pq) {
    if (pq->front == MAX_QUEUE) {
        pq->front = 0;
        pq->size--;
        return pq->entry[0];
    } else {
        pq->size--;
        return pq->entry[pq->front++];
    }
}

bool emptyQueue(Queue *pq) {
    return pq->size == 0;
}

bool fullQueue(Queue *pq) {
    return pq->size == MAX_QUEUE;
}

void clearQueue(Queue *pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void traverseQueue(Queue *pq, void (*pf)(QueueEntry)) {
    int pos = pq->front;
    for (int s = 0; s < pq->size; s++) {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % MAX_QUEUE;
    }

}

void print(QueueEntry i) {
    printf("%d", i);
}

#else
void intialQueue(Queue*pq){
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}

void append(QueueEntry item,Queue*pq){
    QueueNode *pn= (QueueNode*)malloc(sizeof(QueueNode));
    pn->next=NULL;
    pn->entry=item;
    if(pq->rear==NULL){
        pq->front=pn;
        pq->rear=pn;
        pq->size++;
    }else{
        pq->rear->next=pn;  //for link
        pq->rear=pn;
        pq->size++;
    }


}

QueueEntry serve(Queue*pq){
    QueueNode*pn=pq->front;
    QueueEntry item =pn->entry;

    pq->front=pq->front->next;
    free(pn);
    if(pq->front==NULL)
        pq->rear=NULL;
    pq->size--;
    return item;
}
bool emptyQueue(Queue*pq){
    return pq->size==0;
}

void clearQueue(Queue*pq){
    while(pq->front!=NULL){
        pq->front->next=pq->rear;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size=0;
}
void traverseQueue(Queue*pq,void (*pf)(QueueEntry)){
    QueueNode*pn=pq->front;
    while(pn){
        (*pf)(pn->entry);
        pn=pn->next;
    }
}
#endif