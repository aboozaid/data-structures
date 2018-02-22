#include "StackCalls.h";

bool Stack::StackEmpty(Stack *ptr) {
	return !ptr->top;
}
bool Stack::StackFull(Stack *ptr) {
	return ptr->top >= MAXSTACK;
}
void Stack::push(int num, Stack *ptr) {
	if (!StackFull(ptr))
		ptr->entry[ptr->top++] = num;
}
void Stack::pop(int *num, Stack *ptr) {
	if (!StackEmpty(ptr))
		*num = ptr->entry[--ptr->top];
}
void Stack::StackTop(int *topnum, Stack *ptr) {
	if (!StackEmpty(ptr))
		*topnum = ptr->entry[ptr->top - 1];
}
void Stack::StackClear(Stack *ptr) {
	ptr->top = 0;
}