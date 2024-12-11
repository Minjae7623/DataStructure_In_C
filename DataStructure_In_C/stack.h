#pragma once
typedef int element; //data type.

typedef struct stackType
{
	element* stack;
	int capacity;
	int top;
}stackType;

void InitStack(stackType* s);
void FreeStack(stackType* s);
int IsFull(stackType* s);
int IsEmpty(stackType* s);
void Push(stackType* s, element item);
element Pop(stackType* s);
element Peek(stackType* s);