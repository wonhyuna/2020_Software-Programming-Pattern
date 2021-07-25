#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE* next;
	int num;
}Node;

void insert(Node* q, int num)
{
	Node *p = (Node*)malloc(sizeof(Node));

	p->next = q->next;
	p->num = num;
	q->next = p;
	printf("%d\n", num);
}

int main() 
{
	Node *first = (Node*)malloc(sizeof(Node));
	first->next = NULL;

	printf("number: ");
	int ex;
	scanf_s("%d", &ex);

	insert(first, ex);
	insert(first, 100);
	insert(first, 250);
	insert(first, 467);

	free(first);

	return 0;
}