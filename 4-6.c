#include <Stdio.h>

void extend(double *a, double *p, double *q);

void main()
{
	double amount[10];
	double price[10] = { 10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98 };
	double quantity[10] = { 4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8 };

	extend(amount, price, quantity);

	for (int i = 0; i < 10; i++)
	{
		printf("amount: %lf \n", amount[i]);
	}
}

void extend(double *a, double *p, double *q)
{
	for (int i = 0; i < 10; i++)
	{
		*(a + i) = *(p + i) * *(q + i);
	}
}