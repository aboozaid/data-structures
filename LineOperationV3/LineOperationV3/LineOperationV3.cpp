// LineOperationV3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include <string.h>
#include <stdlib.h>


bool Mirror(char *l, char *r);
void Display(int result);
int main(int argc, char* argv[])
{
	queue l;
	Stack r;
	CreateQueue(&l);
	CreateStack(&r);
	ElementType *rword, *lword, word[50];
	scanf("%s", word);
	lword = strtok(word, ":");
	rword = strtok(NULL, ":");
	if (rword && lword) {
		int leftch = strlen(lword) - 1, rightch = strlen(rword) - 1;
		if (leftch > rightch) {
			Display(2);
			return EXIT_SUCCESS;
		}
		else {
			if (leftch < rightch) {
				Display(3);
				return EXIT_SUCCESS;
			}
			else
			{
				while (leftch >= 0 && rightch >= 0) {
					enqueue(lword[leftch], &l);
					Push(rword[rightch], &r);
					leftch--;
					rightch--;
				}
			}
		}
	} else
		Display(0);
	while (!StackEmpty(&r) && !QueueEmpty(&l)) {
			dequeue(lword, &l);
			Pop(rword, &r);
			if (Mirror(lword, rword))
				Display(1);
	}
	return EXIT_SUCCESS;
}
bool Mirror(char *l, char *r) {
	if (*l == *r)
		return true;
	return false;
}
void Display(int result) {
	switch (result) {
	case 0:
		printf("\nN colon not found\n");
		break;
	case 1:
		printf("\nM two strings are mirror\n");
		break;
	case 2:
		printf("\nL the left side larger than the right side\n");
		break;
	default:
		printf("\nR the right side larger than the left side\n");
		break;
	}
}