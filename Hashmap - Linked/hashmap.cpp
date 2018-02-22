#include "stdafx.h"
#include "hashmap.h"
void CreateHashmap(Multimap *ptr) {
	ptr->head = NULL;
	ptr->keysize = 0;
}
void add(EntryType e, Multimap *ptr) {
	if (!ptr->head) {
		key *newkeysize = (key *)malloc(sizeof(key));
		value *newvalue = (value *)malloc(sizeof(value));
		newkeysize->keydata = e.key;
		newkeysize->next = newkeysize;
		newkeysize->previous = newkeysize;
		newvalue->valuedata = e.value;
		newvalue->next = newvalue;
		newvalue->previous = newvalue;
		newkeysize->headofvalues = newvalue;
		ptr->head = newkeysize;
		ptr->keysize++;
		ptr->head->valuesize = 0;
		ptr->head->valuesize++;
	}
	else {
		for (int keysizesnum = ptr->keysize; keysizesnum>0; keysizesnum--) {
			if (ptr->head->keydata == e.key) {
				value *newvalue = (value *)malloc(sizeof(value));
				newvalue->valuedata = e.value;
				newvalue->next = newvalue;
				newvalue->previous = newvalue;
				newvalue->next = ptr->head->headofvalues->next;
				newvalue->previous = ptr->head->headofvalues;
				ptr->head->headofvalues->next->previous = newvalue;
				ptr->head->headofvalues->next = newvalue;
				ptr->head->headofvalues = newvalue;
				ptr->head->valuesize++;
				return;
			}
			ptr->head = ptr->head->next;
		}
		key *newkey = (key *)malloc(sizeof(key));
		value *newvalue = (value *)malloc(sizeof(value));
		newkey->keydata = e.key;
		newkey->headofvalues = NULL;
		newkey->next = newkey;
		newkey->previous = newkey;
		newvalue->valuedata = e.value;
		newvalue->next = newvalue;
		newvalue->previous = newvalue;
		newkey->next = ptr->head->next;
		newkey->previous = ptr->head;
		newkey->headofvalues = newvalue;
		ptr->head->next->previous = newkey;
		ptr->head->next = newkey;
		ptr->head = newkey;
		ptr->keysize++;
		ptr->head->valuesize = 0;
		ptr->head->valuesize++;
	}
}
void removal(type *oldkeysize, Multimap *ptr) {
	key *oldkeytemp;
	for (;; ptr->head = ptr->head->next) {
		if (ptr->head->keydata == oldkeysize) {
			oldkeytemp = ptr->head;
			ptr->head->previous->next = ptr->head->next;
			ptr->head->next->previous = ptr->head->previous;
			ptr->head = ptr->head->next;
			ptr->keysize--;
			free(oldkeytemp);
			break;
		}
	}
}
void modification(type *newvalue, EntryType e,Multimap *ptr) {
	for (;; ptr->head = ptr->head->next) {
		if (ptr->head->keydata == e.key) {
			for (;; ptr->head->headofvalues = ptr->head->headofvalues->next) {
				if (ptr->head->headofvalues->valuedata == e.value) {
					ptr->head->headofvalues->valuedata = newvalue;
					break;
				}
			}
			break;
		}
	}
}
/*void lookup(type *oldkeysize, void(*display)(EntryType), Multimap *ptr) {
	EntryType e;
	for (;; ptr->head = ptr->head->next) {
		if (ptr->head->keydata == oldkeysize) {
			for (int valuessum = ptr->head->valuesize; valuessum>0; valuessum--) {
				e.key = ptr->head->keydata;
				e.value = ptr->head->headofvalues->valuedata;
				(*display)(e);
				ptr->head->headofvalues = ptr->head->headofvalues->next;
			}
			break;
		}
	}
}*/