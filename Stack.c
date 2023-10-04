#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define DOUBLE_TRESHOLD 4096


typedef struct{
	int* items;
	int top;
	int size;
} Stack;

void init(Stack* s)
{
	s->top = -1;
	s->size = 0;
	s->items = NULL;
}

void destroy(Stack* s)
{
	if(s->size > 0)
	{
		free(s->items);
		s->top = -1;
		s->size = 0;
	}
}

void push(Stack* s, int element)
{
	s->top += 1;
	if(s->size == s->top)
	{
		int* new_items = NULL;
		if(s->size == 0)
		{
			s->size += 1;
		}
		else if(s->size < DOUBLE_TRESHOLD)
		{
			s->size *= 2;
		}
		else
		{
			s->size += 128;
		}
		new_items = realloc(s->items, s->size * sizeof(int));
        if (new_items == NULL)
        {
            printf("Memory allocation failed during push operation.\n");
            abort();
        }
        s->items = new_items;
    }
    s->items[s->top] = element;
}

int pop(Stack* s)
{
	if(s->top == -1)
	{
		printf("The stack is empty, unable to perform operation.");
		abort();
	}
	s->top -= 1;
	return s->items[s->top + 1];
}

int top(Stack* s)
{
	if(s->top == -1)
	{
		printf("The stack is empty, unable to perform operation.");
		abort();
	}
	return s->items[s->top];
}

bool isEmpty(Stack* s)
{
	return (s->top == -1);
}