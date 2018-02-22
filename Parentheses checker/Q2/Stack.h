#pragma once
typedef char Stack[20];
bool isEmpty(Stack *);
bool isFull(Stack *);
void CreateStack(Stack *);
void Push(char , Stack *);
void Pop(char *, Stack *);
void ClearStack(Stack *);