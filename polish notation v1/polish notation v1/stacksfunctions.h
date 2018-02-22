#include <iostream>

#define MAXSTACKS 50
//#define InfixtoPostfix
#define Evaluatepostfix

#ifdef InfixtoPostfix
class stack {
private:
	int top;
	char entry[MAXSTACKS];
public:
	stack() {
	top = 0;
	}
	bool StackEmpty(stack *ptr);
	bool StackFull(stack *ptr);
	void Push(char e, stack *ptr);
	void Pop(char *e, stack *ptr);
	void StackTop(char *stop, stack *ptr);
	bool StackClear(stack *ptr);
};
#endif // linkedlist

#ifdef Evaluatepostfix

class stack {
private:
	int top;
	char entry[MAXSTACKS];
public:
	stack() {
		top = 0;
	}
	bool StackEmpty(stack *ptr);
	bool StackFull(stack *ptr);
	void Push(char e, stack *ptr);
	void Pop(char *e, stack *ptr);
	void StackTop(char *stop, stack *ptr);
	bool StackClear(stack *ptr);
};
#endif // EvaluatePostfix

