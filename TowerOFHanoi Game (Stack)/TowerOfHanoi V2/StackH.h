#pragma once
#include <iostream>
using namespace std;
#define MAXSTACK 20
#define ArrayStack
#ifdef ArrayStack
struct Stack {
	int top;
	int entry[MAXSTACK];
};
void CreateStack(Stack *ptr);
bool StackEmpty(Stack *ptr);
bool StackFull(Stack *ptr);
void Push(int disk, Stack *ptr);
void Pop(int *disk, Stack *ptr);
void StackClear(Stack *ptr);

#endif // ArrayStack

