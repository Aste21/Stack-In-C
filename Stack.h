#pragma once

typedef struct{
	int* items;
	int topElement;
	size_t size;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
int top(const Stack* s);
bool isEmpty(const Stack* s);
