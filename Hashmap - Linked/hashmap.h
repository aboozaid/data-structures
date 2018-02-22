#pragma once
#include "global.h"
typedef char type;
struct value {
		type valuedata[50];
		struct value *next;
		struct value *previous;
};
struct key {
		type *keydata;
		value *headofvalues;
		struct key *next;
		struct key *previous;
		int valuesize;
};
typedef struct multimap {
	key *head;
	int keysize;
}Multimap;
void CreateHashmap(Multimap *ptr);
void add(EntryType e, Multimap *ptr);
void removal(type *oldkey, Multimap *ptr);
void modification(type *newvalue, EntryType e, Multimap *ptr);
void lookup(type *oldkey,void (*display)(EntryType ), Multimap *ptr);