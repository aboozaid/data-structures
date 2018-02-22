#pragma once
#include <iostream>
#define MAXSTACK 50
#define InfixtoPostfix
#ifdef InfixtoPostfix
class stack {
private:
	int top;
	char entry[MAXSTACK];
public:
	stack() {
		top = 0;
	}
	bool StackEmpty(stack *ptr);
	bool StackFull(stack *ptr);
	void Push(char e, stack *ptr);
	void Pop(char *e, stack *ptr);
	void StackTop(char *stop,stack *ptr);
	void StackClear(stack *ptr);
};
#endif // InfixtoPostfix
