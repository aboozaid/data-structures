#include "stdafx.h"
#include "ListDefenitions.h"
void CreateList(List *ptr) {
	ptr->current = NULL;
	ptr->currentpos = 0;
	ptr->size = 0;
}
bool InsertList(int p, Entry e, List *ptr) {
	listnode *pn = (listnode *)malloc(sizeof(listnode));
	if (p <= ptr->currentpos) {
		for (; ptr->currentpos != p; ptr->currentpos--)
			ptr->current = ptr->current->previous;
	 }
	else {
		for (; ptr->currentpos != p; ptr->currentpos++)
			ptr->current->next == NULL ? 0 : ptr->current = ptr->current->next;
	}
	if (pn) {
		if (p == 0 && !ptr->current) {
			pn->nodeData = e;
			pn->next = ptr->current;
			pn->previous = ptr->current;
			ptr->current = pn;
		}
		else if (p == 0 && ptr->current) {
			pn->nodeData = e;
			pn->next = ptr->current;
			pn->previous = ptr->current->previous;
			ptr->current->previous = pn;
			ptr->current = pn;
		}
		else {
			if (ptr->current->next == NULL) {
				pn->nodeData = e;
				pn->next = ptr->current->next;
				pn->previous = ptr->current;
				ptr->current->next = pn;
				ptr->current = pn;
			}
			else {
				pn->nodeData = e;
				pn->next = ptr->current;
				pn->previous = ptr->current->previous;
				ptr->current->previous = pn;
				pn->previous->next = pn;
				ptr->current = pn;
			}
		}
		ptr->size++;
		return true;
	}
	else return false;
}
bool SequentialSearch(keyType e, List *ptr) {
	for (int i = 0; i < ptr->size; i++) {
		if (EQ(e, ptr->current->key)) {
			return true;
		}
	}
	return false;
}