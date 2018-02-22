/*
	Author: Assem Abozaid
	Script: Polish notation
	flaw: isn't support evaluate postfix - you can do it by your own
		  only operators [+,-,*,/,^] are supported
*/
#include <iostream>
#include "stackfunctions.h"

using namespace std;
// Functions prototype
void InfixToPostfixCH(char infix[]); // arrays passes as reference remember*
void InfixToPostfixNUM(char infix[]); // arrays passes as reference remember*
bool IsdigitCH(char *checktoken); // pointers help here to pass as reference - Copy will be wast of memory
bool IsdigitNUM(char *checktoken); // pointers help here to pass as reference - Copy will be wast of memory
bool Isoperator(char *token); // pointers help here to pass as reference - Copy will be wast of memory
int Precedence(char operators); // you will understand it below

void main() {
	cout << "Welcome to infix/postfix calculator" << endl; // just a message
	for (;;) // tell the compiler to repeat the statements bellow everytime until user exit
	{
		char infix[25];
		int options;
		cout << "\n1- type expressions in characters\n2- type expressions in numbers" << endl; // message
		cin >> options;
		switch (options) { // switch is most efficient here than if because I don't need to do any operation before executing
		case 1:	
			// switch also high performance than if but just a little bit
			cout << "enter your expression: " << endl; // message
			cin >> infix;
			InfixToPostfixCH(infix); // call the function to do the task after finish the whole main will be repeated
			break; // to prevent execute the result two times so break immediately
		case 2:
			cout << "enter your expression: " << endl; // message
			cin >> infix;
			InfixToPostfixNUM(infix); // call the function to do the task after finish the whole main will be repeated
			break; // to prevent execute the result two times so break immediately
		default:
			exit(0); // exit the program for invalid number
		}
	}
}
/* 
This two functions responsible to check the entered expression with a little bit limitation
Job: 
1- create the stack
2- Check if there open and close brackets so inside will be given precedence
3- Can take more than one character/number because we don't evaluate yet
4- Unary operators are not allowed
6- Any characters FROM A TO Z are allowed UPPERCASE only
7- Transfer from infix to postfix for characters/numbers only
Limitation:
1- Only positive numbers
2- Uppercase characters only
3- no spaces between character and operators
...
Precondition: Array initialize and fill
Postcondition: your postfix must be ready to use
*/
void InfixToPostfixCH(char infix[]) {
	char postfix[25],op;
	int i = 0, j = 0;
	stack polish;
	while (infix[i] != '\0') // loop through the array until it's end
	{
		if (infix[i] == '(') // if you found an open bracket push it to stack
			polish.Push(infix[i], &polish); 
		else if (IsdigitCH(&infix[i])) // check whether is character or not
			postfix[j++] = infix[i]; // store it to postfix array
		else if (Isoperator(&infix[i])) { // check whether is operator or not
			if (!polish.StackEmpty(&polish)) // check first the stack is not empty if true push the operator into stack
			{ // if false means there is another operator stored in the stack so we have to check the precedence
				polish.StackTop(&op, &polish); // take the stored operator - take care about first in first out
				while (!polish.StackEmpty(&polish) && Precedence(op) >= Precedence(infix[i])) // looping until check which operator have the high precedence to put in array
				{
					polish.Pop(&op, &polish); // pop this operator from the stack
					postfix[j++] = op; // store it in postfix function
					if (!polish.StackEmpty(&polish)) // if still there is another operators
						polish.StackTop(&op, &polish); // take the stored operator and then looping again
				}
			}
			polish.Push(infix[i], &polish); // if true condition
		}
		else if (infix[i] == ')') { // if you finally find close bracket
			polish.StackTop(&op, &polish); // take the stored operator
			while (op != '(') // start looping until reach to the open bracket
			{
				polish.Pop(&op, &polish); // pop this from the stack 
				postfix[j++] = op; // store it into the postfix array
				polish.StackTop(&op, &polish); // stored operator in op variable again and start loop again
			}
			polish.Pop(&op, &polish); // to pop open bracket from expression
		}
		else // for anything wrong signs or operators 
		{
			cout << "Invalid characters" << endl;
			polish.StackClear(&polish);
			exit(0);
		}
		i++; // increment I to get the next character 
	}
	while (!polish.StackEmpty(&polish)) { // after finish there will be some operators will less precedence stored in the stack so we have to store them in postfix
		polish.Pop(&op, &polish); // pop it from the stack
		postfix[j++] = op; // stored them
	}
	postfix[j] = '\0'; // to get rid of garbage values
	cout << postfix << endl; // Finally display the expression after modification
}
void InfixToPostfixNUM(char infix[]) {
	char postfix[25], op;
	int i = 0, j = 0;
	stack polish;
	while (infix[i] != '\0') // loop through the array until it's end
	{
		if (infix[i] == '(') // if you found an open bracket push it to stack
			polish.Push(infix[i], &polish);
		else if (IsdigitNUM(&infix[i])) // check whether is number or not
			postfix[j++] = infix[i]; // store it to postfix array
		else if (Isoperator(&infix[i])) { // check whether is operator or not
			if (!polish.StackEmpty(&polish)) // check first the stack is not empty if true push the operator into stack
			{ // if false means there is another operator stored in the stack so we have to check the precedence
				polish.StackTop(&op, &polish); // take the stored operator - take care about first in first out
				while (!polish.StackEmpty(&polish) && Precedence(op) >= Precedence(infix[i])) // looping until check which operator have the high precedence to put in array
				{
					polish.Pop(&op, &polish); // pop this operator from the stack
					postfix[j++] = op; // store it in postfix function
					if (!polish.StackEmpty(&polish)) // if still there is another operators
						polish.StackTop(&op, &polish); // take the stored operator and then looping again
				}
			}
			polish.Push(infix[i], &polish); // if true condition
		}
		else if (infix[i] == ')') { // if you finally find close bracket
			polish.StackTop(&op, &polish); // take the stored operator
			while (op != '(') // start looping until reach to the open bracket
			{
				polish.Pop(&op, &polish); // pop this from the stack 
				postfix[j++] = op; // store it into the postfix array
				polish.StackTop(&op, &polish); // stored operator in op variable again and start loop again
			}
			polish.Pop(&op, &polish); // to pop open bracket from expression
		}
		else // for anything wrong signs or operators 
		{
			cout << "Something is not clear" << endl;
			polish.StackClear(&polish);
			exit(0);
		}
		i++; // increment I to get the next number 
	}
	while (!polish.StackEmpty(&polish)) { // after finish there will be some operators with less precedence stored in the stack so we have to store them in postfix
		polish.Pop(&op, &polish); // pop it from the stack
		postfix[j++] = op; // stored them
	}
	postfix[j] = '\0'; // to get rid of garbage values
	cout << postfix << endl; // Finally display the expression after modification
}
/* 
Pretty easy to understand just check the character/number
Precondition: Array initialized and filled
Postcondition: return true or false
*/
bool IsdigitCH(char *checktoken)
{
	return (*checktoken >= 'A' && *checktoken <= 'Z'); // return true otherwise false
}
bool IsdigitNUM(char *checktoken)
{
	return (*checktoken >= '0' && *checktoken <= '9'); // return true otherwise false
}
/* 
Check valid operators
Precondition: Array initialized and filled
Postcondition: return true or false
*/
bool Isoperator(char *token) {
	switch (*token) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
		return true;
	}
	return false;
}
/* 
just check which operator has the high precedence
Precondition: stack initialized and filled
Postcondition: return high precedence
*/
int Precedence(char operators) {
	switch (operators) {
	case '+':
	case '-':
		return 1; // low precedence
	case '*':
	case '/' :
		return 2; // a little precedence
	case '^':
		return 3; // max number because high precedence
	}
	return 0; // otherwise zero
}