// QueueLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "QueueLinked.h"
void display(ElementType e) {
	printf("%d\n", e);
}
void main()
{
	Queue s,cp;
	CreateQueue(&s);
	CreateQueue(&cp);
	int y;
	if (!QueueFull(&s)) {
		Enqueue(500, &s);
		Enqueue(600, &s);
		Enqueue(700, &s);
		Enqueue(800, &s);
		Enqueue(900, &s);
		Enqueue(1000, &s);
	}
	Dequeue(&y, &s);
	TraversQueue(&s, display);
	ElementType d;
	LastElement(&s, &d);
	printf("\n%d", d);
	CopyQueue(&s, &cp);
	TraversQueue(&cp, display);
}

