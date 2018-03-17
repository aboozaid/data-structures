// Macros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void change(int *x) {
	*x = 15;
}
#define foo(f) change(&f);
#define min(a,b) (a < b ? (a): (b))

int main()
{
	int y = 20;
	foo(y);
	int x = min(8||8 ? 1: 9, 5);
	printf("%d\n", y);

    return 0;
}

