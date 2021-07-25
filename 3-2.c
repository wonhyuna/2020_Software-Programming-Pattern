//p.36_3


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct members
{
	int id;
	char lastname[20];
	float pay_rate;
	float hours_worked;
};

int main()
{
	struct members employees[6] = { {3462, "Jones", 4.62, 40.0}, {6793, "Robbins", 5.83, 38.5},
	{6985, "Smith", 5.22, 45.5}, {7834, "Swain", 6.89, 40.0}, 
	{8867, "Timmins", 6.43, 35.5}, {9002, "Williams", 4.75, 42.0} };
	
	float grosspay[6];
	float totpay=0;

	for (int i = 0; i < 6; i++)
	{
		grosspay[i] = employees[i].pay_rate * employees[i].hours_worked;
		totpay = totpay + grosspay[i];
	}

	for (int i = 0; i < 6; i++)
	{
		printf("ID Number: %d\t Name: %s\t Pay Rate: %.2f\t Hours Worked: %.1f\t Gross Pay: %.3f\n",
			employees[i].id, employees[i].lastname, employees[i].pay_rate, employees[i].hours_worked, grosspay[i]);
	}
	printf("Total Gross Pay is %.3f", totpay);
}


