#include "stdafx.h"
#include "ListDefinistions.h"
void CreateList(List *ptr) {
	ptr->head = NULL;
	ptr->size = 0;
}
bool ListEmpty(List *ptr) {
	return  !ptr->size;
}
bool ListEmpty(List ptr) {
	return !ptr.size;
}
bool ListFull(List *ptr) {
	return false;
}
int ListSize(List *ptr) {
	return ptr->size;
}
void ListDestroy(List *ptr) {
	ptr->head = NULL;
	ptr->size = 0;
}
int InsertList(int p, ListEntry e, List *ptr) {
	listnode *lnew = (listnode *)malloc(sizeof(listnode));
	listnode *le = (listnode *)malloc(sizeof(listnode));
	if (lnew && le) {
		le->entry = e;
		le->next = NULL;
		if (p == 0) {
			le->next = ptr->head;
			ptr->head = le;
		}
		else {
			int i;
			for (lnew = ptr->head, i = 0; i < p-1; i++)
				lnew = lnew->next;
			le->next = lnew->next;
			lnew->next = le;
		}
		ptr->size++;
		return 1;
	}
	else return 0;
}
int DeleteList(int p, ListEntry *e, List *ptr) {
	listnode *ldel = (listnode *)malloc(sizeof(listnode));
	listnode *le = (listnode *)malloc(sizeof(listnode));
	if (ldel && le) {
		if (p == 0) {
			le = ptr->head;
			*e = le->entry;
			ptr->head = le->next;
			free(le);
		}
		else {
			int i;
			for (ldel = ptr->head, i = 0; i < p-1; i++)
				ldel = ldel->next;
			le = ldel->next;
			*e = le->entry;
			ldel->next = le->next;
			free(le);
		}
		ptr->size--;
		return 1;
	}
	else return 0;
}
int RetrieveList(int p, ListEntry *e, List *ptr) {
	listnode *lnew = (listnode *)malloc(sizeof(listnode));
	if (lnew) {
		int i;
		for (lnew = ptr->head, i = 0; i < p; i++)
			lnew = lnew->next;
		*e = lnew->entry;
		return 1;
	}
	else return 0;
}
int ReplaceList(int p, ListEntry e, List *ptr) {
	listnode *lnew = (listnode *)malloc(sizeof(listnode));
	if (lnew) {
		int i;
		for (lnew = ptr->head, i = 0; i < p; i++)
			lnew = lnew->next;
		lnew->entry = e;
		return 1;
	}
	else return 0;
}