#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *next;
}NODE;

int InsertKey(NODE *head, int n, NODE *newnode);
void ScanList(NODE *first);

int main()
{
	NODE *head = (NODE*)malloc(sizeof(NODE));
	NODE *node = (NODE*)malloc(sizeof(NODE) * 7);

	head->next = &node[0];
	node[0].key = 100;
	node[0].next = &node[1];
	node[1].key = 250;
	node[1].next = &node[2];
	node[2].key = 467;
	node[2].next = NULL;

	for (int i = 3; i < 7; i++)
	{
		printf("Write the number: ");
		int num;
		scanf_s("%d", &num);

		if (InsertKey(head, num, &node[i]) == 0)
		{
			printf("Insert was successful\n\n");
		}
		else
		{
			printf("Insert was fail\n\n");
		}
	}
	NODE* first = head->next;

	ScanList(first);
}

int InsertKey(NODE *head, int n, NODE *newnode)
{
	NODE *first = head->next;
	NODE *last = head;

	newnode->key = n;

	while (first != NULL)
	{
		if (first->key == newnode->key)
		{
			printf("key already exists\n");
			return -1;
		}
		else if (first->key > newnode->key)
		{
			last->next = newnode;
			newnode->next = first;
			return 0;
		}
		else if ((first->key < newnode->key) && (first->next == NULL))
		{
			first->next = newnode;
			newnode->next = NULL;
			return 0;
		}
		last = first;
		first = first->next;
	}
	return 1;
}

void ScanList(NODE *first)
{
	int i = 0;
	while (first != NULL)
	{
		printf("%d\t", first->key);
		first = first->next;
		i++;
	}
}