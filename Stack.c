#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "Stack.h"

#define DOUBLE_TRESHOLD 4096
#define BASIC_TOP_VALUE -1
#define SIZE_INCREMENT 128

void init(Stack *s)
{
	s->topElement = BASIC_TOP_VALUE;
	s->size = 0;
	s->items = NULL;
}

void destroy(Stack *s)
{
	if (s->size > 0)
	{
		free(s->items);
		s->topElement = BASIC_TOP_VALUE;
		s->size = 0;
	}
}

void push(Stack *s, int element)
{
	s->topElement += 1;
	if (s->size == s->topElement)
	{
		int *newItems = NULL;
		if (s->size == 0)
		{
			s->size += 1;
		}
		else if (s->size < DOUBLE_TRESHOLD)
		{
			s->size *= 2;
		}
		else
		{
			if (s->size += SIZE_INCREMENT < SIZE_MAX)
			{
				s->size += SIZE_INCREMENT;
			}
			else
			{
				if (s->size + 1 < SIZE_MAX)
				{
					s->size += 1;
				}
				else
				{
					printf("Unable to perform push operation as the size is too big.");
					destroy(s);
					exit(EXIT_FAILURE);
				}
			}
		}
		newItems = realloc(s->items, s->size * sizeof(int));
		if (newItems == NULL)
		{
			printf("Memory allocation failed during push operation.\n");
			destroy(s);
			exit(EXIT_FAILURE);
		}
		s->items = newItems;
	}
	s->items[s->topElement] = element;
}

int pop(Stack *s)
{
	if (s->topElement == BASIC_TOP_VALUE)
	{
		printf("The stack is empty, unable to perform operation.");
		destroy(s);
		exit(EXIT_FAILURE);
	}
	s->topElement -= 1;
	return s->items[s->topElement + 1];
}

int top(Stack *s)
{
	if(s->topElement == BASIC_TOP_VALUE)
	{
		printf("The stack is empty, unable to perform operation.");
		destroy(s);
		exit(EXIT_FAILURE);
	}
	return s->items[s->topElement];
}

bool isEmpty(Stack *s)
{
	return (s->topElement == BASIC_TOP_VALUE);
}
