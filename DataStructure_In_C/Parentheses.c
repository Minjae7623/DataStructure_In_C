#include<stdio.h>
#include"stack.h"

int ParenthesesCheck(stackType* stack, char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '[' || str[i] == '{' || str[i] == '(')
		{
			Push(stack, str[i]);
		}
		else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
		{
			if (IsEmpty(stack))
				return 0;

			if (str[i] == ']' && Peek(stack) == '[')
				Pop(stack);
			else if (str[i] == '}' && Peek(stack) == '{')
				Pop(stack);
			else if (str[i] == ')' && Peek(stack) == '(')
				Pop(stack);
			else
				return 0;
		}

		i++;
	}

	return(IsEmpty(stack));
}