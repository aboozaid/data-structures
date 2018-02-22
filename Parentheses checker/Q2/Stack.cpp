#include "stdafx.h"
#include "Stack.h"
bool isEmpty(Stack *ptr) {
	return !(*ptr)[(*ptr)[0]];
}
bool isFull(Stack *ptr) {
	return (*ptr)[(*ptr)[0]] == 10;
}
void CreateStack(Stack *ptr) {
	(*ptr)[0] = { 0 };
}
void Push(char e, Stack *ptr) {
	(*ptr)[++(*ptr)[0]] = e;
}
void Pop(char *e, Stack *ptr) {
	*e = (*ptr)[(*ptr)[0]--];
}
void ClearStack(Stack *ptr) {
	(*ptr)[0] = { 0 };
}