// BinaryTreeStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binarytree.h"

void display(EntryType *e) {
	printf("%s\t%d\n", e->paths, e->key);
}
struct ss {
	int emp[50];
};
typedef ss *t;
int main()
{
/*	EntryType info;
	TreeType bst;
	CreateTree(&bst);
	scanf("%s", info.paths);
	scanf("%d", &info.key);
	Insert(&bst, info);
	scanf("%s", info.paths);
	scanf("%d", &info.key);
	Insert(&bst, info);
	scanf("%s", info.paths);
	scanf("%d", &info.key);
	Insert(&bst, info);
	scanf("%s", info.paths);
	scanf("%d", &info.key);
	Insert(&bst, info);
	scanf("%s", info.paths);
	scanf("%d", &info.key);
	Insert(&bst, info);*/
	t *y = (t*)malloc(sizeof(t));
	(*y)->emp[(*y)->emp[0]] = 5;
	/*scanf("%s", info.paths);
	scanf("%d", &info.key);
	Delete(&bst, info);*/
	/*system("@cls||clear");
	InorderTree(&bst, display);
	PreorderTree(&bst, display);
	PostOrderTree(&bst, display);*/
	/*printf("%d", TreeSize(&bst));
	search(&bst, &info);*/
    return 0;
}

