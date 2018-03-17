#pragma once
#include "stdafx.h"
#define MAXQUEUE 20
typedef char ElementType;
struct queue {
	int front, rear, size;
	ElementType entry[MAXQUEUE];
};
void CreateQueue(queue *);
bool QueueEmpty(queue *);
void enqueue(ElementType, queue *);
void dequeue(ElementType *, queue *);


