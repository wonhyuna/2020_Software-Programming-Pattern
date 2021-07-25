#include <stdio.h>

void liquid(int cup, int*gallons, int*quarts, int*pint, int*cups);

void main()
{
	int num1, num2, num3, num4, num5;
	printf("write the number: ");
	scanf_s("%d", &num1);

	liquid(num1, &num2, &num3, &num4, &num5);
	printf("gallons: %d\n", num2);
	printf("quarts: %d\n", num3);
	printf("pints: %d\n", num4);
	printf("cups: %d\n", num5);
}

void liquid(int total, int*gallons, int*quarts, int*pints, int*cups)
{
	*gallons = total / 16;
	*quarts = (total%16) / 4;
	*pints = (total % 16 % 4) / 2;
	*cups = total % 16 % 4 % 2;

}