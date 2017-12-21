#include "Stacks.h"

bool::stack::StackFull(stack *ptr)
	{
		if (ptr->top == MAXSTACK)
			return true;
		else
			return false;
	}
bool::stack::StackEmpty(stack *ptr)
	{
	if (ptr->top == 0)
		return true;
	else
		return false;
	}
void::stack::Push(char *e, stack *ptr) {
		ptr->entry[ptr->top++] = *e;
	}
void::stack::Pop(char *e, stack *ptr)
	{
		*e = ptr->entry[--ptr->top];
	}
void::stack::TraversStack(stack *ptr, void(*ds)(char e))
	{
		for (int i = ptr->top; i > 0; i--)
			(*ds)(ptr->entry[i - 1]);
	}
void::stack::StackTop(char *e, stack *ptr) 
	{
	*e = ptr->entry[ptr->top-1];
	}
void::stack::StackClear(stack *ptr)
	{
		ptr->top = 0;
	}
