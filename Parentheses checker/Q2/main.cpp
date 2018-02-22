// Q2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#define open(a) ((a) == '(' || (a) == '{' || (a) == '[')
#define close(b) ((b) == ')' || (b) == '}' || (b) == ']')
#define itsclose(a,b) ((a) - (b) == 1 || (a) - (b) == 2)
bool checkparenth(char x, Stack *ps);
int main()
{
	Stack p;
	CreateStack(&p);
	char exp[] = "[(a+b)*[{c+k]/{x-y}]";
	for (int i = 0; exp[i] != '\0'; i++) {
		if (open(exp[i]) || close(exp[i])) {
			if (checkparenth(exp[i], &p))
				continue;
			else break;
		}
	}
	isEmpty(&p) ? printf("ordering") : printf("not ordering");
    return 0;
}
bool checkparenth(char x, Stack *ps) {
	if (open(x)) Push(x, ps);
	else {
		char y;
		Pop(&y, ps);
		if (itsclose(x, y)) return true;
		else return false;
	}
}

