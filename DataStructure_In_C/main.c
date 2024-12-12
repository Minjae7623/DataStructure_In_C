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

	PrintInfixToPostfix(stack, UserInput());
	//PrintPostfix(stack, UserInput());//input infix

	FreeStack(stack);
	free(stack);

	return 0;
}