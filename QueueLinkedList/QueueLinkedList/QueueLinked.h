#pragma once
#define ElementType int

typedef struct queuenode {
	ElementType entry;
	struct queuenode *next;
}QueueNode;
typedef struct queue {
	queuenode *front, *rear;
	int size;
}Queue;

void CreateQueue(Queue *ptr);
void Enqueue(ElementType e, Queue *ptr);
void Dequeue(ElementType *, Queue *ptr);
bool QueueEmpty(Queue *ptr);
bool QueueFull(Queue *ptr);
int QueueSize(Queue *ptr);
void ClearQueue(Queue *ptr);
void TraversQueue(Queue *ptr, void(*display)(ElementType));
void LastElement(Queue *ptr, ElementType *e);
void CopyQueue(Queue *old, Queue *Copy);