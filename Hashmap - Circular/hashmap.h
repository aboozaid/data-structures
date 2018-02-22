#pragma once
#include "global.h"
typedef char type;
struct value {
		type *name;
		struct value *next;
};
struct key {
		type *name;
		value *head;
		struct key *next;
};
typedef struct multimap {
	key *head;
}Multimap;
void CreateHashmap(Multimap *ptr);
void add(EntryType e, Multimap *ptr);
void removal(type *oldkey, Multimap *ptr);
void modification(type *newvalue, EntryType e, Multimap *ptr);
void lookup(type *oldkey,void (*display)(EntryType ), Multimap *ptr);