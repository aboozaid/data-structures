#include "stdafx.h"
#include "hashmap.h"
void CreateHashmap(Multimap *ptr) {
	ptr->head = NULL;
}
void add(EntryType e, Multimap *ptr) {
	if (!ptr->head) {
		key *newkey = (key *)malloc(sizeof(key));
		value *newvalue = (value *)malloc(sizeof(value));
		newkey->name = e.key;
		newkey->head = NULL;
		newkey->next = ptr->head;
		newvalue->name = e.value;
		newvalue->next = NULL;
		newkey->head = newvalue;
		ptr->head = newkey;
	}
	else {
		key *exist;
		value *loop;
		for (exist = ptr->head; exist != NULL; exist = exist->next) {
			if (exist->name == e.key) {
				value *newvalue = (value *)malloc(sizeof(value));
				newvalue->name = e.value;
				newvalue->next = NULL;
				for (loop = exist->head; loop->next != NULL;)
					loop = loop->next;
				newvalue->next = loop->next;
				loop->next = newvalue;
				return;
			}
			if (exist->next == NULL) break; else continue;
		}
		key *newkey = (key *)malloc(sizeof(key));
		value *newvalue = (value *)malloc(sizeof(value));
		newkey->name = e.key;
		newkey->head = NULL;
		newkey->next = exist->next;
		newvalue->name = e.value;
		newvalue->next = NULL;
		exist->next = newkey;
		newkey->head = newvalue;
	}
}
void removal(type *oldkey, Multimap *ptr) {
	key *exist = ptr->head;
	key *oldkeytemp;
	value *oldvaluetemp;
	for (; exist != NULL; exist = exist->next) {
		if (exist->name == oldkey) {
			oldkeytemp = exist;
			ptr->head = exist->next;
			free(oldkeytemp);
			break;
		}
		else {
			if (exist->next->name == oldkey) {
				oldkeytemp = exist->next;
				exist->next = exist->next->next;
				free(oldkeytemp);
				break;
			}
		}
	}
}
void modification(type *newvalue, EntryType e,Multimap *ptr) {
	key *exist = ptr->head;
	value *check;
	for (; exist != NULL; exist = exist->next) {
		if (exist->name == e.key) {
			for (check = exist->head; check != NULL; check = check->next) {
				if (check->name == e.value) {
					check->name = newvalue;
					break;
				}
			}
			break;
		}
	}
}
void lookup(type *oldkey, void(*display)(EntryType), Multimap *ptr) {
	key *exist = ptr->head;
	value *check;
	EntryType e;
	for (; exist != NULL; exist = exist->next) {
		if (exist->name == oldkey) {
			for (check = exist->head; check != NULL; check = check->next) {
				e.key = exist->name;
				e.value = check->name;
				(*display)(e);
			}
		}
	}
}