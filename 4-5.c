#include <Stdio.h>

void show(double *r);

void main()
{
	double rates[9] = { 6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0 };
	show(rates);
}

void show(double *r)
{
	for (int i = 0; i < 9; i++)
	{
		printf("%.1lf\n", *(r+i));
	}
}

