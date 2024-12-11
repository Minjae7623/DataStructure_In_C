#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#define DEFAULT_SIZE 10


void InitStack(stackType* s)
{
	s->top = -1;
	s->capacity = DEFAULT_SIZE;
	s->stack = (element*)malloc(s->capacity * sizeof(element));
}

void FreeStack(stackType* s)
{
	free(s->stack);
}

int IsFull(stackType* s)
{
	return (s->top == (s->capacity - 1));
}

int IsEmpty(stackType* s)
{
	return (s->top == -1);
}

void Push(stackType* s, element item)
{
	if (IsFull(s))
	{
		s->capacity *= 2;// is full -> x2
		s->stack = (element*)realloc(s->stack, s->capacity * sizeof(element));
	}

	s->stack[++(s->top)] = item;
}

element Pop(stackType* s)
{
	if (IsEmpty(s))
	{
		puts("Error: Underflow");
		return;
	}
	else
		return s->stack[(s->top)--];
}

element Peek(stackType* s)
{
	if (IsEmpty(s))
	{
		puts("Error: Underflow");
		return;
	}
	else
		return s->stack[s->top];
}
