#include <iostream>
#include "StackH.h"

using namespace std;

// functions prototypes
void DisksMovements(int disksnum, Stack *start, Stack *temp, Stack *finish);
void ApplyMoves(Stack *start, Stack *finish, char *s, char *f);
void DisplayMovement(char *from, char *to, int disk);

void main() {
	Stack start, temp, finish;
	CreateStack(&start);
	CreateStack(&temp);
	CreateStack(&finish);
	DisksMovements(3, &start, &temp, &finish);
	getchar();
}
void DisksMovements(int disksnum, Stack *start, Stack *temp, Stack *finish) {
	int num_of_moves, i=1;
	char s = 'S', t = 'T', f = 'F';
	if (disksnum % 2 == 0)
	{
		char temp = f;
		f = t;
		t = temp;
	}
	num_of_moves = (int)pow(2, disksnum)-1;
	while (disksnum != 0) {
		Push(disksnum, start);
		disksnum--;
	}
	while (i <= num_of_moves) {
		if (i % 3 == 1)
			ApplyMoves(start, finish, &s, &f);
		else if (i % 3 == 2)
			ApplyMoves(start, temp, &s, &t);
		else
			ApplyMoves(temp, finish, &t, &f);
		i++;
	}
}
void ApplyMoves(Stack *start, Stack *finish, char *s, char *f) {
	int pole1, pole2;
	Pop(&pole1, start);
	Pop(&pole2, finish);
	if (pole1 == 0)
	{
		Push(pole2, start);
		DisplayMovement(f, s, pole2);
	}
	else if (pole2 == 0)
	{
		Push(pole1, finish);
		DisplayMovement(s, f, pole1);
	}
	else if (pole1 > pole2) {
		Push(pole1, start);
		Push(pole2, start);
		DisplayMovement(f,s, pole2);
	}
	else
	{
		Push(pole2, finish);
		Push(pole1, finish);
		DisplayMovement(s, f, pole1);
	}
}
void DisplayMovement(char *from, char *to, int disk) {
	cout << "Move Disk " << disk << " From " << *from << " To " << *to << endl;
}