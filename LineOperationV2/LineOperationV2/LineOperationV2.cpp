// LineOperationV2.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include "stdafx.h"
#include <string.h>
#include "Queue.h"
#include "Stack.h"

void main()
{
	queue l, r;
	Stack mirror;
	ElementType word[50], lc, rc,sc;
	CreateQueue(&l);
	CreateQueue(&r);
	CreateStack(&mirror);
	printf("enter your words seperated by colon\n");
	scanf("%s", word);
	int i, colon = 0,left=0,right=0,diff=0,same=0,mirr=0;
	for (i = 0; word[i] != '\0'; i++) {
		if (word[i] == ':') {
			colon = 1;
			for (int j = i + 1; word[j] != '\0'; j++)
			{
				enqueue(word[j], &r);
				Push(word[j], &mirror);
			}
			break;
		}
		enqueue(word[i], &l);
	}
	while (!QueueEmpty(&l) || !QueueEmpty(&r)) {
		dequeue(&lc, &l);
		dequeue(&rc, &r);
		Pop(&sc, &mirror);
		if (QueueEmpty(&l) && !QueueEmpty(&r))
		{
			right = 1;
			mirr = 0;
			same = 0;
			diff = 0;
			break;
		}
		else if (!QueueEmpty(&l) && QueueEmpty(&r))
		{
			left = 1;
			mirr = 0;
			same = 0;
			diff = 0;
			break;
		}
		else {

			if (sc == lc) {
				mirr = 1;
			}
			else if (lc == rc) {
				same = 1;
			}
			else
				diff = 1;
		}
	}
	if (colon == 0)
		printf("N\n");
	else if (left != 0)
		printf("L\n");
	else if (right != 0)
		printf("R\n");
	else if (diff != 0 )
		printf("D\n");
	else if (mirr != 0)
		printf("M\n");
	else
		printf("S\n");
}

