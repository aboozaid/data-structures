#pragma once
typedef struct entrytype {
	char paths[50];
	int key = 0;
}EntryType;
typedef struct node {
	EntryType data;
	node *right;
	node *left;
}Node;
typedef Node *TreeType;
void CreateTree(TreeType *);
bool TreeEmpty(TreeType *);
bool TreeFull(TreeType *);
int TreeSize(TreeType *);
int TreeDepth(TreeType *);
void TreeClear(TreeType *);
void InorderTree(TreeType *, void(*Display)(EntryType *));
void PreorderTree(TreeType *, void(*Display)(EntryType *));
void PostOrderTree(TreeType *, void(*Display)(EntryType *));
void Insert(TreeType *, EntryType );
void Delete(TreeType *, EntryType );
bool search(TreeType *, EntryType *);

