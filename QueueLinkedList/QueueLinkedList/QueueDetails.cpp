#include "stdafx.h"
#include <stdlib.h>
#include "QueueLinked.h"
void CreateQueue(Queue *ptr) {
	ptr->front = NULL;
	ptr->rear = NULL;
	ptr->size = 0;
}
void Enqueue(ElementType e, Queue *ptr) {
	QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->entry = e;
	pn->next = NULL;
	ptr->rear == NULL ? ptr->front = pn : ptr->rear->next = pn;
	ptr->rear = pn;
	ptr->size++;
}
void Dequeue(ElementType *e, Queue *ptr) {
	QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn = ptr->front;
	*e = pn->entry;
	ptr->front = ptr->front->next;
	ptr->front == NULL ? ptr->rear = NULL : 0;
	ptr->size--;
	free(pn);
}
bool QueueEmpty(Queue *ptr) {
	return !ptr->size;
}
bool QueueFull(Queue *ptr) {
	return false;
}
int QueueSize(Queue *ptr) {
	return ptr->size;
}
void ClearQueue(Queue *ptr) {
	while (ptr->front != NULL) {
		ptr->rear = ptr->front->next;
		free(ptr->front);
		ptr->front = ptr->rear;
	}
	ptr->size = 0;
}
void TraversQueue(Queue *ptr, void(*display)(ElementType)) {
	for (QueueNode *pn = ptr->front; pn; pn = pn->next) {
		(*display)(pn->entry);
	}
}
void LastElement(Queue *ptr, ElementType *e) {
	*e = ptr->rear->entry;
}
void CopyQueue(Queue *old, Queue *Copy) {
	Copy->front = old->front;
	Copy->rear = old->rear;
	Copy->size = old->size;
	
}