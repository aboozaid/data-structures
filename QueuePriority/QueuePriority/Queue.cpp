#include "stdafx.h"
#include "Queue.h"
void CreateQueue(Queue *ptr) {
	ptr->front = 0;
	ptr->rear = -1;
	ptr->size = 0;
}
void Enqueue(QueueEntry e, Queue *ptr) {
	ptr->rear = (ptr->rear + 1) % MAXQUEUE;
	ptr->entry[ptr->rear] = e;
	ptr->size++;
	for (int i = ptr->front, s = 0; s <= ptr->size; s++) {
		for (int j = i + 1; j <= ptr->size; j++) {
			if (ptr->entry[i].priority < ptr->entry[j].priority) {
				QueueEntry temp;
				temp = ptr->entry[i];
				ptr->entry[i] = ptr->entry[j];
				ptr->entry[j] = temp;
			}
		}
	}
}
void Dequeue(QueueEntry *e, Queue *ptr) {
	*e = ptr->entry[ptr->front];
	ptr->front = (ptr->front + 1) % MAXQUEUE;
	ptr->size--;
}
void TraverseQueue(Queue *ptr, void(*display)(QueueEntry)) {
	for (int i = ptr->front, s = 0; s < ptr->size; s++) {
		(*display)(ptr->entry[i]);
		i = (i + 1) % MAXQUEUE;
	}
}
int QueueSize(Queue *ptr) {
	return ptr->size;
}
bool IsEmpty(Queue *ptr) {
	return !ptr->size;
}