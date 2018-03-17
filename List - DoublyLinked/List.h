#pragma once

typedef int keyType;
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LE(a, b) ((a) <= (b))
#define GT(a, b) ((a) > (b))
#define GE(a, b) ((a) >= (b))
struct listnode {
	Entry nodeData;
	keyType key;
	struct listnode *next, *previous;
};
struct Entry {
	int age;
	float salary;
	char name[20];
};
typedef struct list {
	listnode *current;
	int size, currentpos;
}List;
void CreateList(List *);
bool InsertList(int, Entry, List *);
//bool DeleteList(int, Entry *, List *); // implement it by your own
bool SequentialSearch(keyType, List *);

