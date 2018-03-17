#include "stdafx.h"
#include "Stack.h"
void CreateStack(Stack *ptr) {
	ptr->top = 0;
}
bool StackEmpty(Stack *ptr) {
	return !ptr->top;
}
bool StackFull(Stack *ptr) {
	return ptr->top == 50;
}
void push(TreeType e, Stack *ptr) {
	ptr->entry[ptr->top++] = e;
}
void pop(TreeType *stored, Stack *ptr) {
	*stored = ptr->entry[--ptr->top];
}
void Travers(Stack *ptr, void(*display)(TreeType c)) {
	for (int i = ptr->top-1; i >= 0; i--) {
		(*display)(ptr->entry[i]);
	}
}