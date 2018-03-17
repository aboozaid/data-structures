#include "stdafx.h"
#include "queue.h"

class queuenode {
public:
	queuenode *next;
	void *entry;
};
queue::queue() {
	front = NULL;
	rear = NULL;
	size = 0;
}
bool queue::isEmpty(queue *ptr) {
	return !ptr->size;
}
bool queue::isFull(queue *ptr) {
	return false;
}
void queue::Enqueue(void *item, queue *ptr, int size) {
	void *ptrq = new void*;
	memcpy(ptrq, item, size);
	queuenode *pn = new queuenode();
	pn->entry = ptrq;
	pn->next = NULL;
	ptr->rear == NULL ? ptr->front = pn : ptr->rear->next = pn;
	ptr->rear = pn;
	ptr->size++;
}
void queue::Dequeue(void *stored, queue *ptr, int size) {
	void *ptrq = new void*;
	ptrq = ptr->front->entry;
	memcpy(stored, ptr->front->entry, size);
	ptr->front = ptr->front->next;
	ptr->front == NULL ? ptr->rear = NULL : 0;
	ptr->size--;
	delete(ptrq);
}

queue::~queue()
{
	while (front != NULL) {
		rear = front->next;
		delete(front);
		front = rear;
	}
	size = 0;
}
