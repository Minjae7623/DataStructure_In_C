#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#include"ui.h"

int main()
{
	stackType* stack = (stackType*)malloc(sizeof(stackType));
	InitStack(stack);
	//PrintParentheses(stack, UserInput());
	PrintPostfix(stack, UserInput());

	FreeStack(stack);
	free(stack);

	return 0;
}