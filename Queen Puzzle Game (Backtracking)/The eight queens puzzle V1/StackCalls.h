#pragma once
#include <iostream>
using namespace std;

#define MAXSTACK 20
#define StackArray

#ifdef StackArray
class Stack {
	int top;
	int entry[MAXSTACK];
	bool StackEmpty(Stack *ptr);
	bool StackFull(Stack *ptr);
public:
	Stack() {
		top = 0;
	}
	void push(int num, Stack *ptr);
	void pop(int *num, Stack *ptr);
	void StackTop(int *topnum, Stack *ptr);
	void StackClear(Stack *ptr);
};

#endif // Stack-Array

