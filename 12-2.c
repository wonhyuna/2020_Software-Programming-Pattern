#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE *next;
	int num;
}Node;

int insert(Node *q, int num);
int delete(Node *q);

int main() 
{
	Node* first = (Node*)malloc(sizeof(Node));
	first->next = NULL;

	printf("number: ");
	int ex;
	scanf_s("%d", &ex);

	insert(first, 50);
	insert(first, 100);
	if (ex == 100)
	{
		delete(first);
	}
	insert(first, 250);
	insert(first, 467);


	Node* t = first->next;
	while (t != NULL)
	{
		printf("%d\n", t->num);
		t = t->next;
	}

	free(first);

	return 0;
}

int insert(Node *q, int num)
{
	Node *p = (Node*)malloc(sizeof(Node));

	p->next = q->next;
	p->num = num;
	q->next = p;
	return 0;
}

int delete(Node *q)
{
	Node *r = (Node*)malloc(sizeof(Node));
	r = q->next;
	q->next = r->next;
	free(r);
	return 0;
}