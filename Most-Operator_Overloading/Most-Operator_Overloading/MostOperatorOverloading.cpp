// MostOperatorOverloading.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stdafx.h"
#include "queue.h"
#include "calculator.h"

using namespace std;


void main()
{
	char input[50];
	scanf("%s", input);
	queue savedinputs;
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] != 'A-Z')
			savedinputs.Enqueue((void*)&input[i], &savedinputs, sizeof(input[i]));
		else
			break;
	}
	calculator temp, result;
	char fnum, lnum;
	savedinputs.Dequeue((void*)&fnum, &savedinputs, sizeof(fnum));
	char op;
	while (!savedinputs.isEmpty(&savedinputs)) {
		savedinputs.Dequeue((void*)&op, &savedinputs, sizeof(op));
		savedinputs.Dequeue((void*)&lnum, &savedinputs, sizeof(lnum));
		if (op == '+')
		{
			result = temp + (fnum + lnum);
			fnum = (fnum + lnum);
		}
		else if (op == '-')
		{
			result = temp - (fnum - lnum);
			fnum = (fnum - lnum);
		}
		else if (op == '*')
		{
			result = temp * float((float)fnum * (float)lnum);
			fnum = (fnum * lnum);
		}
		else
		{
			result = temp / (fnum / lnum);
			fnum = (fnum / lnum);
		}
	}
	result.display(&result);
}

