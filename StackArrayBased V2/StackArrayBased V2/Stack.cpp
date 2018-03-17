#include "stdafx.h"
#include "Stack.h"

void CreateStack(StackType *ptr) {
	(*ptr)[0] = { 0 };
}
bool StackEmpty(StackType *ptr) {
	return !(*ptr)[(*ptr)[0]];
}
bool StackFull(StackType *ptr) {
	return (*ptr)[(*ptr)[0]] == 10;
}
void Push(char e, StackType *ptr) {
	(*ptr)[++(*ptr)[0]] = e;
}
void Pop(char *e, StackType *ptr) {
	*e = (*ptr)[(*ptr)[0]--];
}

void ClearStack(StackType *ptr) {
	(*ptr)[0] = { 0 };
}