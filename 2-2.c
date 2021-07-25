#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct cal {
	char name[20];
	double seps;
	double pter;
};

int main()
{
	for (int i = 0; i < 5; i++)
	{
		struct cal c1;
		double calculate;

		scanf_s("%s", c1.name);
		scanf_s("%lf", &c1.seps);
		scanf_s("%lf", &c1.pter);
		calculate = c1.seps * c1.pter;

		printf("회사이름: %s\n", c1.name);
		printf("계산 결과: %lf\n", calculate);
	}
	return 0;
}
