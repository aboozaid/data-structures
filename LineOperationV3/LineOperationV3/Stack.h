#pragma once
typedef char Stack[20];
bool StackEmpty(Stack *);
bool StackFull(Stack *);
void CreateStack(Stack *);
void Push(char , Stack *);
void Pop(char *, Stack *);
void ClearStack(Stack *);