#include "stdafx.h"
#include "ListDefinition.h"
void CreateList(List *ptr) {
	ptr->size = 0;
}
bool ListEmpty(List *ptr) {
	return !ptr->size;
}
bool ListFull(List *ptr) {
	return ptr->size == MAXLIST;
}
int ListSize(List *ptr) {
	return ptr->size;
}
void ListDestroy(List *ptr) {
	ptr->size = 0;
}
void InsertList(int p, ListEntry e, List *ptr) {
	for (int i = ptr->size - 1; i >= p; i--)
		ptr->entry[i + 1] = ptr->entry[i];
	ptr->entry[p] = e;
	ptr->size++;
}
void DeleteList(int p, ListEntry *e, List *ptr) {
	*e = ptr->entry[p];
	for (int i = p + 1; i < ptr->size; i++)
		ptr->entry[i - 1] = ptr->entry[i];
	ptr->size--;
}
void RetrieveList(int p, ListEntry *e, List *ptr) {
	*e = ptr->entry[p];
}
void ReplaceList(int p, ListEntry e, List *ptr) {
	ptr->entry[p] = e;
}
void TraversList(List *ptr, void(*Display)(ListEntry)) {
	for (int i = 0; i < ptr->size; i++)
		(*Display)(ptr->entry[i]);
}