/*
	Author: Assem Abozaid
	Script: Polish notation
	flaw: isn't support evaluate postfix - you can do it by your own
		  only operators [+,-,*,/,^] are supported
		  Only numbers and no interface connection
		  only positive integers, no error handling and much more

		  * the best is to try to solve this limitation as much as you can
*/
#include <iostream>
#include "stacksfunctions.h"

using namespace std;
// functions prototype
void InfixToPostfix(char infix[], char postfix[]);
int HigherPrec(char op1, char op2);

void main()
{
	char infix[] = "9+4/3-7";
	char postfix[80];
	InfixToPostfix(infix, postfix);
	cout << "The postfix of your infix is :" << postfix << " " << endl;
	getchar();
}
void InfixToPostfix(char infix[], char postfix[]) {
	stack polish; // create the stack
	char op;
	int j=0;
	for (int i = 0; infix[i] != '\0'; i++) // loop throught the array
	{
		if (infix[i] >= '0' && infix[i] <= '9') // check if it number or operator
			postfix[j++] = infix[i]; // store it in the postfix
		else // if it found operator
		{
			if (!polish.StackEmpty(&polish)) // check first the stack empty or not if true just push the operator
			{
				polish.StackTop(&op, &polish); // take the first operator in the stack
				while (!polish.StackEmpty(&polish) && HigherPrec(op, infix[i])) // loop until it empty and check precedence
				{
					polish.Pop(&op, &polish); // pop the operator from the stack
					postfix[j++] = op; // store it in the postfix array
					if (!polish.StackEmpty(&polish)) // if there is still operators in the stack loop again
						polish.StackTop(&op, &polish); // take the second operator in the stack
				}
			}
			polish.Push(infix[i], &polish); // push the operator
		}
	}
	while (!polish.StackEmpty(&polish)) { // store the old operator which stored in the stack into postfix
		polish.Pop(&op, &polish);
		postfix[j++] = op;
	}
	postfix[j] = '\0'; // prevent garbage values
}
int HigherPrec(char op1, char op2) {
	if (op1 == '$') // high precedence
		return 1;
	else if (op1 == '*' || op1 == '/') // low precedence
		return (op2 != '$'); // return true if op2 not a $ sign otherwise false
	else if (op1 == '+' || op1 == '-') // a little precedence
		return (op2 != '$') && (op2 != '*') && (op2 != '/'); // return true if op2 not equal to all this signs otherwise false
	return 0;
}
