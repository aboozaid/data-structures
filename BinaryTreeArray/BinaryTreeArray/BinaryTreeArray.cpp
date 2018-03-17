// BinaryTreeArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binarytree.h"

int main()
{
	EntryType data;
	TreeType bst;
	CreateTree(&bst);
	scanf("%d", &data);
	insert(&bst, data);
	scanf("%d", &data);
	insert(&bst, data);
	scanf("%d", &data);
	insert(&bst, data);
	scanf("%d", &data);
	insert(&bst, data);
	scanf("%d", &data);
	insert(&bst, data);
	scanf("%d", &data);
	insert(&bst, data);
	scanf("%d", &data);
	insert(&bst, data);
	search(&bst, &data);
	scanf("%d", &data);
	removes(&bst, &data);
    return 0;
}

