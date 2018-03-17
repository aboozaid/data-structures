#include "stdafx.h"
#include "binarytree.h"
void CreateTree(TreeType *ptr) {
	
}
void insert(TreeType *ptr, EntryType data) {
	int curindex = 0;
	while (true) {
		if (ptr->data[curindex] == NULL) {
			ptr->data[curindex] = data;
			break;
		}
		else if (ptr->data[curindex] < data)
			curindex = (2 * curindex + 2);
		else 
			curindex = (2 * curindex + 1);
	}
}
int search(TreeType *ptr, EntryType *data) {
	int found, curindex=0;
	while (true) {
		if (ptr->data[curindex] == *data) {
			found = ptr->data[curindex];
			break;
		}
		else if (ptr->data[curindex] < *data)
			curindex = (2 * curindex + 2);
		else
			curindex = (2 * curindex + 1);
	}
	return found;
}
void removes(TreeType *ptr, EntryType *data) {
	int curindex = 0;
	while (true) {
		if (ptr->data[curindex] == *data) {
			if (ptr->data[(2 * curindex) + 1] == NULL) {
				ptr->data[curindex] = ptr->data[(2 * curindex) + 2];
			}
			else if (ptr->data[(2 * curindex) + 2] == NULL)
				ptr->data[curindex] = ptr->data[(2 * curindex) + 1];
			else {
				int oldindx = curindex;
				curindex = (2 * oldindx) + 1;
				if (ptr->data[(2 * curindex) + 2] == NULL) {
					ptr->data[oldindx] = ptr->data[curindex];
					ptr->data[(2 * oldindx) + 1] = ptr->data[(2 * curindex) + 1];
				}
				else {
					for (; ptr->data[curindex] == NULL; (2 * curindex) + 2);
					ptr->data[oldindx] = ptr->data[((2 * curindex) + 2)-1];
					ptr->data[((2 * curindex) + 2) - 1] = NULL;
				}
			}
			break;
		}
		else if (ptr->data[curindex] < *data)
			curindex = (2 * curindex + 2);
		else
			curindex = (2 * curindex + 1);
	}
}