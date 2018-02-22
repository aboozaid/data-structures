#include "stacksfunctions.h"
bool stack::StackEmpty(stack *ptr) {
	if (ptr->top == 0)
		return true;
	else
		return false;
}
bool stack::StackFull(stack *ptr) {
	if (ptr->top = MAXSTACKS)
		return true;
	else
		return false;
}
void stack::Push(char e, stack *ptr) {
	ptr->entry[ptr->top++] = e;
}
void stack::Pop(char *e, stack *ptr) {
	*e = ptr->entry[--ptr->top];
}
void stack::StackTop(char *stop, stack *ptr) {
	*stop = ptr->entry[ptr->top - 1];
}
bool stack::StackClear(stack *ptr) {
	if (ptr->top != 0)
	{
		ptr->top = 0;
		return true;
	}
	else
		return false;
}