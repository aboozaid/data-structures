// StackArrayBasedV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
void Display(StackType s);
void main()
{
	StackType test;
	int s;
	CreateStack(&test);
	char x;
	while (true) {
		x = getchar();
		Push(x, &test);
	}
	if (!StackFull(&test)) {
		Push(5, &test);
		Push(8, &test);
		Push(14, &test);
	}
	
}

void Display(StackType s) {
	printf("%d\t", s);
}