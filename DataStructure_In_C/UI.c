#include<stdio.h>
#include"stack.h"
#include"ui.h"
#include"Parentheses.h"
#include"PostfixExpression.h"

char* UserInput()
{
	static char input[32]; //지역변수로 하면 값 날라감.
	gets_s(input, sizeof(input));
	return input;
}

void PrintParentheses(stackType* stack, char* str)
{
	if (ParenthesesCheck(stack, str))
		printf("result: pass!");
	else
		printf("result: fail...");
}

void PrintPostfix(stackType* stack, char* str)
{
	printf("%s = %d", str, Postfix(stack, str));
}