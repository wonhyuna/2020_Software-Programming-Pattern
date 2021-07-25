#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int n = -1;

void push(int);
int pop();
int stack_full();
int stack_empty();

int main() 
{

	while (1) 
	{
		int choice;
		int data;
		printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
		printf("1: append\t2: remove\t3: print\n");
		printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");

		printf("Enter the number: ");
		scanf_s("%d", &choice);

		switch (choice) 
		{
		case 1:
			if (stack_full() == -1)
				printf("Stack is full.\n");
			else 
			{
				printf("Append number: ");
				scanf_s("%d", &data);
				push(data);
				printf("Insert complete\n");
			}
			break;

		case 2:
			if (stack_empty() == 1)
				printf("Stack is empty.\n");
			else 
			{
				pop();
				printf("Remove complete\n");
			}
			break;

		case 3:
			if (stack_empty() == 1)
				printf("Stack is empty.\n");
			else 
			{
				for (int i = 0; i <= n; i++)
				{
					printf("%d ", stack[i]);
				}
				printf("\n");
			}
			break;
		}
	}

}

void push(int data) 
{
	if (stack_full() == 0) 
	{
		n++;
		stack[n] = data;
	}
}

int pop() 
{
	if (stack_empty() == 0) 
	{
		int temp = stack[n];
		n--;
		return temp;
	}
}

int stack_full() 
{
	if (n >= SIZE - 1)
	{
		return -1;
	}
	else
		return 0;
}

int stack_empty() 
{
	if (n == -1)
	{
		return 1;
	}
	return 0;
}