#pragma once

typedef struct{
	int* items;
	int top;
	int size;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
int top(Stack* s);
bool isEmpty(Stack* s);