#include "stdafx.h"
#include "binarytree.h"
#include "Stack.h"

void CreateTree(TreeType *ptr) {
	(*ptr) = NULL;
}
bool TreeEmpty(TreeType *ptr) {
	return !(*ptr);
}
bool TreeFull(TreeType *ptr) {
	return false;
}
/*int TreeSize(TreeType *ptr) {
	if (!(*ptr)) // implement this also in stack don't forget
		return 0;
	return (1 + TreeSize(&(*ptr)->left) + TreeSize(&(*ptr)->right));
}*/
int TreeSize(TreeType *ptr) {
	int counter = 0;
	Stack roots;
	CreateStack(&roots);
	Node *q = (*ptr);
	do {
		while (q) {
			if (q->left || q->right)
				push(q, &roots);
			q = q->left;
			counter++;
		}
		StackEmpty(&roots) == false ? pop(&q, &roots) : 0;
		if (q) q = q->right;
	} while (q);
	return counter;
}
int TreeDepth(TreeType *ptr) { // implement this also in stack don't forget
	if (!(*ptr))
		return 0;
	int l = TreeDepth(&(*ptr)->left);
	int r = TreeDepth(&(*ptr)->right);
	return (l > r) ? l++ : r++;
}
void TreeClear(TreeType *ptr) { // implement this in stack
	if ((*ptr)) {
		TreeClear(&(*ptr)->left);
		TreeClear(&(*ptr)->right);
		free(*ptr);
		(*ptr) = NULL;
	}
}
// implement these three functions in stack
void InorderTree(TreeType *ptr, void(*Display)(EntryType *data)) { 
	if ((*ptr)) {
		InorderTree(&(*ptr)->left, Display);
		(*Display)(&(*ptr)->data);
		InorderTree(&(*ptr)->right, Display);
	}
}
void PreorderTree(TreeType *ptr, void(*Display)(EntryType *data)) {
	if ((*ptr)) {
		(*Display)(&(*ptr)->data);
		PreorderTree(&(*ptr)->left, Display);
		PreorderTree(&(*ptr)->right, Display);
	}
}
void PostOrderTree(TreeType *ptr, void(*Display)(EntryType *data)) {
	if ((*ptr)) {
		PostOrderTree(&(*ptr)->left, Display);
		PostOrderTree(&(*ptr)->right, Display);
		(*Display)(&(*ptr)->data);
	}
}
void Insert(TreeType *ptr, EntryType data) {
	Node *block = (Node *)malloc(sizeof(Node));
	block->data = data;
	block->left = NULL;
	block->right = NULL;
	if (!(*ptr))
		(*ptr) = block;
	else {
		Node *q = (*ptr);
		while (q) {
			if (q->data.key > data.key && q->left)
					q = q->left;
			else if (q->data.key < data.key && q->right)
					q = q->right;
			else
				break;
		}
		if (q->data.key > data.key)
			q->left = block;
		else
			q->right = block;
	}
}
void Delete(TreeType *ptr, EntryType data) {
	Node *q = *ptr;
	int flage = 0;
	while (q && !(flage=(q->data.key == data.key))) {
		if (q->data.key > data.key)
			q = q->left;
		else
			q = q->right;
	}
	if (flage) {
		Node *temp = q;
		if (!q->left) {
			q = q->right;
		}
		else if (!q->right)
			q = q->left;
		else {
			q = q->left;
			if (!q->right) {
				temp->data = q->data;
				temp->left = q->left;
			}
			else {
				Node *parent = q;
				for (; q->right; q = q->right)
					parent = q;
				temp->data = q->data;
				parent->right = q->left;
				temp = q;
			}
		}
		free(temp);
	}
}
bool search(TreeType *ptr, EntryType *data) {
	if ((*ptr)->data.key == data->key)
		return true;
	else if ((*ptr)->data.key < data->key)
		search(&(*ptr)->right, data);
	else
		search(&(*ptr)->left, data);
}