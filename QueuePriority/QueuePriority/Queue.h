#pragma once
#define MAXQUEUE 50

struct process {
	int id, priority;
};
typedef process QueueEntry;
typedef struct queue {
	int front, rear, size;
	QueueEntry entry[MAXQUEUE];
}Queue;

void CreateQueue(Queue *);
void Enqueue(QueueEntry, Queue *);
void Dequeue(QueueEntry *, Queue *);
void TraverseQueue(Queue *, void(*display)(QueueEntry));
int QueueSize(Queue *);
bool IsEmpty(Queue *);
