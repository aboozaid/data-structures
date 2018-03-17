#pragma once

typedef char StackType[10];
bool StackEmpty(StackType *);
bool StackFull(StackType *);
void CreateStack(StackType *);
void Push(char, StackType *);
void Pop(char *, StackType *);
void ClearStack(StackType *);