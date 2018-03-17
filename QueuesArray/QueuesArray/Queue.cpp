#include "stdafx.h"
#include "QueueCalls.h"

void CreateQueue(Queue* ptr) {
	ptr->front = 0;
	ptr->rear = -1;
	ptr->size = 0;
}
bool QueueEmpty(Queue* ptr) {
	return !ptr->size;
}
bool QueueFull(Queue* ptr) {
	return ptr->size == MAXQUEUE;
}
void Enqueue(char e, Queue* ptr) {
	ptr->rear = (ptr->rear + 1) % MAXQUEUE;
	ptr->entry[ptr->rear] = e;
	ptr->size++;
}
void Dequeue(char *e, Queue* ptr) {
	*e = ptr->entry[ptr->front];
	ptr->front = (ptr->front + 1) % MAXQUEUE;
	ptr->size--;
}
void QueueClear(Queue* ptr) {
	ptr->front = 0;
	ptr->rear = -1;
	ptr->size = 0;
}
void QueueTraverse(Queue* ptr, void(*display)(char *c)) {
	for (int i = ptr->front, s = 0; s <= ptr->rear; s++)
	{
		(*display)(&ptr->entry[i]);
		i = (i + 1) % MAXQUEUE;
	}
}
void LastElement(Queue *ptr, char *e) {
	*e = ptr->entry[ptr->size - 1];
}
void CopyQueue(Queue *old, Queue *Copy) {
	for (int i = old->front; i < old->size; i = (i + 1) % MAXQUEUE) {
		Copy->entry[i] = old->entry[i];
		Copy->size++;
	}
	Copy->rear = old->rear;
}