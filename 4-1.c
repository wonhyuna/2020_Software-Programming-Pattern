#include <stdio.h>

void change(float t, int *q, int *d, int *n, int *p);

void main()
{
	float total;
	int *quarter, *dime, *nickel, *penny;

	printf("total: ");
	scanf_s("%f", &total);

	change(total, &quarter, &dime, &nickel,&penny);

	printf("quarters: %d\n", quarter);
	printf("dimes: %d\n", dime);
	printf("nickels: %d\n", nickel);
	printf("pennies: %d\n", penny);
}

void change(float t, int *q, int *d, int *n, int *p)
{
	
	int toto;
	toto = t * 100;

	*q = toto / 25;
	*d = (toto % 25) / 10;
	*n = (toto % 25 % 10) / 5;
	*p = toto % 25 % 10 % 5;

}