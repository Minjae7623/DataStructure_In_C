#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 10
#define MAP_SIZE 6


typedef struct element
{
	int y;
	int x;
}element;

typedef struct stackType
{
	element* stack;
	int capacity;
	int top;
}stackType;

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
		s->capacity *= 2;
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

static char map[MAP_SIZE][MAP_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
	{ 'm', '0', '1', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '1' },
	{ '1', '0', '1', '0', '1', '1' },
	{ '1', '0', '1', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1' },
};


int main()
{
	int check = 1;
	stackType* stack = (stackType*)malloc(sizeof(stackType));
	InitStack(stack);

	element start = {1, 0};
	element current = start;

	while (map[current.y][current.x] != 'x')
	{
		map[current.y][current.x] = '1';

		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < MAP_SIZE; j++)
				printf("%c ", map[i][j]);
			putchar('\n');
		}

		if (current.y >= 0 && map[current.y - 1][current.x] != '1') {
			Push(stack, (element) { current.y - 1, current.x });
		}
		if (current.y < MAP_SIZE - 1 && map[current.y + 1][current.x] != '1') {
			Push(stack, (element) { current.y + 1, current.x });
		}
		if (current.x >= 0 && map[current.y][current.x - 1] != '1') {
			Push(stack, (element) { current.y, current.x - 1 });
		}
		if (current.x < MAP_SIZE - 1 && map[current.y][current.x + 1] != '1') {
			Push(stack, (element) { current.y, current.x + 1 });
		}

		if (IsEmpty(stack)) 
		{
			check = 0;
			break;
		}

		current = Pop(stack);
		putchar('\n');
	}

	if (check)
		printf("escape! \n");
	else
		printf("mouse can't escape... \n");

	FreeStack(stack);
	free(stack);

	return 0;
}

//Improvements
//Error Handling, Simplified Logic, Visited Marking.