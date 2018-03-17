//#define GLOBAL_H
#include "stdafx.h"
#include "binarytree.h"

typedef struct stack {
	int top;
	TreeType entry[50];
}Stack;
void CreateStack(Stack *ptr);
bool StackEmpty(Stack *ptr);
bool StackFull(Stack *ptr);
void push(TreeType e, Stack *ptr);
void pop(TreeType *stored, Stack *ptr);
void Travers(Stack *ptr, void (*display)(TreeType c));
