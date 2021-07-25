#include <stdio.h>
#define SIZE 10

int Queue[SIZE];
int front = -1;
int back = -1;

void enqueue(int);
int dequeue();
int queue_full();
int queue_empty();

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
			if (queue_full() == -1) 
			{
				printf("Queue is full.\n");
			}
			else 
			{
				printf("Append number: ");
				scanf_s("%d", &data);
				enqueue(data);
				printf("Insert complete\n");
			}
			break;

		case 2:
			if (queue_empty() == 1)
				printf("Queue is empty.\n");
			else 
			{
				dequeue();
				printf("Remove complete\n");
			}
			break;

		case 3:
			if (queue_empty() == 1)
				printf("Queue is empty.\n");
			else 
			{
				for (int i = front + 1; i <= back; i++) 
				{
					printf("%d ", Queue[i]);
				}
				printf("\n");
			}
			break;
		}
	}
}

void enqueue(int data) 
{
	if (queue_full() == 0) 
	{
		back = (back++) % SIZE;
		Queue[back] = data;
	}
}

int dequeue() 
{
	if (queue_empty() == 0) 
	{
		int temp = Queue[front];
		front = (front++) % SIZE;
		return temp;
	}
}

int queue_full() 
{
	if ((back + 1) % (SIZE + 1) == front) 
	{
		return -1;
	}
	else
		return 0;
}

int queue_empty() 
{
	if (front == back) 
	{
		return 1;
	}
	return 0;
}
