#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


struct {
	char RRN[13];
	char name[20];
	float salary;
	float bonus;
}employee[1000];

int main() {
	for (int i = 0; i < 1000; i++)
	{
		printf("\nThe employee %d's information.\n", i + 1);
		printf("Write RRN: ");
		scanf("%s", employee[i].RRN);
		for (int j = 0; j < i; j++)
		{
			if (strcmp(employee[j].RRN, employee[i].RRN) == 0)
			{
				printf("constraint: unique \n");
				break;
			}

		}
		printf("Write name: ");
		scanf("%s", employee[i].name);
		printf("Write salary: ");
		scanf("%f", &employee[i].salary);
		printf("Type bonus: ");
		scanf("%f", &employee[i].bonus);
		if (employee[i].bonus >= employee[i].salary)
		{
			printf("constraint: bonus < salary\n");
		}
	}
	return 0;
}
