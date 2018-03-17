#pragma once
#define MAXQUEUE 20

typedef struct queue {
	int front, rear, size;
	char entry[MAXQUEUE];
}Queue;

void CreateQueue(Queue* );
bool QueueEmpty(Queue*);
bool QueueFull(Queue*);
void Enqueue(char e, Queue*);
void Dequeue(char *e, Queue*);
void QueueClear(Queue* );
void QueueTraverse(Queue* , void (*display)(char *c));
void LastElement(Queue *ptr, char *e);
void CopyQueue(Queue *old, Queue *Copy);

