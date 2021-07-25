#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node {
	int key;
	struct node *next;
}NODE;

NODE *start = NULL;
int num[10] = { 17, 39, 11, 9, 42, 12, 15, 8, 13, 41 };
void insert(int num);

void main() 
{

	for (int i = 0; i < 10; i++)
	{
		insert(num[i]);
	}
	NODE *first;
	first = start;
	while (first->next != NULL) 
	{
		printf("%d\t", first->key);
		first = first->next;
	}
	printf("%d \n", first->key);
}
void insert(int num) 
{
	NODE *newnode, *first;
	newnode = (NODE *)malloc(sizeof(NODE));
	newnode->next = NULL;
	newnode->key = num;
	first = start;
	if (start == NULL) 
	{
		start = newnode;
		return;
	}
	else if (start->key > newnode->key) 
	{
		newnode->next = start;
		start = newnode;
		return;
	}
	else
	{
		while (first->next != NULL) 
		{
			if (first->next->key > newnode->key) 
			{
				newnode->next = first->next;
				first->next = newnode;
				return;
			}
			first = first->next;
		}
	}
	first->next = newnode;
}
