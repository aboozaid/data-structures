#pragma once
#define ListEntry char
struct listnode {
	ListEntry entry;
	struct listnode *next;
};
typedef struct list {
	listnode *head;
	int size;
}List;
void CreateList(List *);
bool ListEmpty(List *);
bool ListEmpty(List );
bool ListFull(List *);
int ListSize(List *);
void ListDestroy(List *);
int InsertList(int, ListEntry, List *);
int DeleteList(int, ListEntry *, List *);
int RetrieveList(int, ListEntry *, List *);
int ReplaceList(int, ListEntry, List *);
