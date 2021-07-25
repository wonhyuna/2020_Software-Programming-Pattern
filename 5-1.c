#include <stdio.h>

struct Car {
	int carnum;
	float miles;
	float gallons;

};

void cal(struct Car c1[5])
{
	float mpg[5];
	float total = 0;
	float avg;
	int i;

	for (i = 0; i < 5; i++)
	{
		mpg[i] = c1[i].miles / c1[i].gallons;
		total = total + mpg[i];

	}
	avg = total / 5;

	for (i = 0; i < 5; i++)
	{
		printf("Car number: %d, The miles per gallon: %lf \n", c1[i].carnum, mpg[i]);
	}
	printf("average miles per gallon: %lf", avg);
}

int main()
{
	struct Car fivecar[5] = { {25, 1450, 62}, {36, 3240, 136}, {44, 1792, 76}, {52, 2360, 105}, {68, 2114, 67} };
	cal(fivecar);

}