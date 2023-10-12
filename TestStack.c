#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"


int main(int argc, char *argv[])
{ 
	Stack stack;
	init(&stack);
	int choice;
	int input;
	bool loopBool = true;
	while(loopBool)
	{
		printf("Press 1 to test push\nPress 2 to test pop\nPress 3 to test isEmpty");
		printf("\nPress 4 to test top\nPress 5 to turn off program\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nInput the number to be added to stack: ");
				scanf("%d", &input);
				printf("%d", input);
				push(&stack, input);
				break;
			}
			case 2:
			{
				printf("\nPopped element: %d", pop(&stack));
				break;
			}
			case 3:
			{
				printf("\nisEmpty result: %d", isEmpty(&stack));
				break;
			}
			case 4:
			{
				printf("\nTop element: %d", top(&stack));
				break;
			}
			case 5:
			{
				loopBool = false;
				break;
			}
			default:
			{
				printf("\nWrong element sorry.");
			}
		}
		printf("\n");
	}
	destroy(&stack);

	return 0;
} 
