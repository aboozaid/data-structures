#pragma once
#define maxtree 50
#define EntryType int
typedef struct treetype {
	EntryType data[maxtree] = {NULL};
}TreeType;
void CreateTree(TreeType *);
void insert(TreeType *, EntryType );
int search(TreeType *, EntryType *);
void removes(TreeType *, EntryType *);