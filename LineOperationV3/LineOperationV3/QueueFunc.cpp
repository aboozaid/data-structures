#include "stdafx.h"
#include "Queue.h"
void CreateQueue(queue *ptr) {
	ptr->front = 0;
	ptr->rear = -1;
	ptr->size = 0;
}
bool QueueEmpty(queue *ptr) {
	return !ptr->size;
}
void enqueue(ElementType item, queue *ptr) {
	ptr->rear = (ptr->rear + 1) % MAXQUEUE;
	ptr->entry[ptr->rear] = item;
	ptr->size++;
}
void dequeue(ElementType *stored, queue *ptr) {
	*stored = ptr->entry[ptr->front];
	ptr->front = (ptr->front + 1) % MAXQUEUE;
	ptr->size--;
}
