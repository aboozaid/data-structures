// QueuePriority.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"

void AddNewProcess(Queue *, QueueEntry *);
void ServeProcess (Queue *, QueueEntry );
void Display(QueueEntry );
void main()
{
	Queue process;
	CreateQueue(&process);
	QueueEntry info;

	for (;;) {
		printf("1-Add New Process\n2-Serve a process\n3-Display process information\n4-Number of waiting process\n5-Exit\n\n");
		int choose;
		scanf_s("%d", &choose);
		switch (choose) {
		case 1 :
			AddNewProcess(&process, &info);
			break;
		case 2:
			ServeProcess(&process, info);
			break;
		case 3:
			TraverseQueue(&process, Display);
			break;
		case 4:
			printf("%d\n\n",QueueSize(&process));
			break;
		default:
			break;
		}
	}
}
void AddNewProcess(Queue *ptr, QueueEntry *info) {
	scanf_s("%d%d", &info->id, &info->priority);
	Enqueue(*info , ptr);
	printf("Process added successfuly\n\n");
}
void ServeProcess(Queue *ptr, QueueEntry info) {
	Dequeue(&info, ptr);
	printf("%d\t%d\n\n", info.id, info.priority);
}
void Display(QueueEntry info) {
	printf("%d\t%d\n\n", info.id, info.priority);
}