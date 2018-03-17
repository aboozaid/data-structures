// QueuesArray.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include "stdafx.h"
#include "QueueCalls.h"

void Display(char *c) {
	printf("%c", *c);
}
void main()
{
	char *s = "assem mohamed ali";
	Queue q,cp;
	CreateQueue(&q);
	CreateQueue(&cp);
	if (!QueueFull(&q)) {
		for (int i = 0; s[i] != '\0'; i++)
			Enqueue(s[i], &q);
	}
	QueueTraverse(&q, &Display);
	char d;
	LastElement(&q, &d);
	printf("\n%c\n", d);
	CopyQueue(&q, &cp);
	QueueTraverse(&cp, &Display);
	getchar();
}

