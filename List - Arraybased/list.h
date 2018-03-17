#pragma once
#define MAXLIST 50
#define ListEntry char
typedef struct list {
	int size;
	ListEntry entry[MAXLIST];
}List;
void CreateList(List *);
bool ListEmpty(List *);
bool ListFull(List *);
int ListSize(List *);
void ListDestroy(List *);
void InsertList(int, ListEntry, List *);
void DeleteList(int, ListEntry *, List *);
void RetrieveList(int, ListEntry *, List *);
void ReplaceList(int, ListEntry, List *);
void TraversList(List*, void(*Display)(ListEntry));


