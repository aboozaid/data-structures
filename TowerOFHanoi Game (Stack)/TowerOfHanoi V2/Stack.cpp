#include "StackH.h"

void CreateStack(Stack *ptr) {
	ptr->top = 0;
}
bool StackEmpty(Stack *ptr) {
	return !ptr->top;
}
bool StackFull(Stack *ptr) {
	return ptr->top >= MAXSTACK;
}
void Push(int disk, Stack *ptr) {
	if (!StackFull(ptr))
		ptr->entry[ptr->top++] = disk;
}
void Pop(int *disk, Stack *ptr) {
	if (!StackEmpty(ptr))
		*disk = ptr->entry[--ptr->top];
	else
		*disk = 0;
}
void StackClear(Stack *ptr) {
	ptr->top = 0;
}