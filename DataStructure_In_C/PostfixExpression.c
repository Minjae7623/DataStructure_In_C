#include<stdio.h>
#include"stack.h"

int priority(char op)
{
	return (op == '*' || op == '/') ? 2 :
		(op == '+' || op == '-') ? 1 : 0;
}

char* TransInfixToPostfix(stackType* stack, char* str)
{
	static char postfix[32];
	char op = 0;
	int j = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		op = str[i];

		switch (op)
		{
		case '(':
			Push(stack, op);
			break;
		case ')':
			while (Peek(stack) != '(')
				postfix[j++] = Pop(stack);
			Pop(stack); //'(' pop.
			break;
		case '*':
		case '/':
		case '+':
		case '-':
			while (!IsEmpty(stack) && priority(Peek(stack)) >= priority(op))
			{
				postfix[j++] = Pop(stack);
			}
			Push(stack, op);
			break;
			//operand
		default:
			postfix[j++] = op;
		}
	}

	while (!IsEmpty(stack))
		postfix[j++] = Pop(stack);

	postfix[j] = '\0';

	return postfix;
}

int PostfixExpress(stackType* stack, char* str)
{
	int result = 0, operand1, operand2;
	char op = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		op = str[i];

		switch (op)
		{
		case '*':
		case '/':
		case '+':
		case '-':
			operand2 = Pop(stack);
			operand1 = Pop(stack);

			result = (op == '*') ? operand1 * operand2 :
				(op == '/') ? operand1 / operand2 :
				(op == '+') ? operand1 + operand2 :
				operand1 - operand2;

			Push(stack, result);
			break;

		default:
			Push(stack, op - '0');
		}
	}

	return Pop(stack);
}