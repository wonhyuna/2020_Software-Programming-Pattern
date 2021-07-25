#include <stdio.h>

int secs(int* h, int* m, int* s);

void main()
{
	int hours, minutes, seconds;
	int total;

	printf("hour: ");
	scanf_s("%d", &hours);

	printf("minute: ");
	scanf_s("%d", &minutes);

	printf("second: ");
	scanf_s("%d", &seconds);


	total = secs(&hours, &minutes, &seconds);
	printf("total: %d", total);
}

int secs(int* h, int* m, int* s)
{
	int sum = 0;
	sum = sum + *h * 3600 + *m * 60 + *s;
	return sum;
}
