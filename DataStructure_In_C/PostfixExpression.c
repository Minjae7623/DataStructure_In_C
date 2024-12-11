#include<stdio.h>
#include"stack.h"

//int Postfix(stackType* stack, char* str)
//{
//	int result = 0, tmp = 0;
//	char op = 0;
//
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		op = str[i];
//
//		switch (op)
//		{
//		case '*':
//			result = Pop(stack) * Pop(stack);
//			Push(stack, result);
//			break;
//		case '/':
//			tmp = Pop(stack);
//			result = Pop(stack) / tmp;
//			Push(stack, result);
//			break;
//		case '+':
//			result = Pop(stack) + Pop(stack);
//			Push(stack, result);
//			break;
//		case '-':
//			tmp = Pop(stack);
//			result = Pop(stack) - tmp;
//			Push(stack, result);
//			break;
//		default:
//			Push(stack, op - '0');
//		}
//	}
//
//	return Pop(stack);
//}

//improve

int Postfix(stackType* stack, char* str) 
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