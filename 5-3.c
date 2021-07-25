#include <stdio.h>

int Days(struct Date *cal);

struct Date {
	int month;
	int day;
	int year;
};

int Days(struct Date *cal) {
	int *sumptr;
	int sum;
	sumptr = &sum;
	*sumptr = ((*cal).year - 2000) * 360 + ((*cal).month - 1) * 30 + ((*cal).day - 1);
	return *sumptr;
}

void main() {
	struct Date d;
	struct Date *d1;
	d1 = &d;

	int result;

	printf("write the month: ");
	scanf_s("%d", &(d1->month));

	printf("write the day: ");
	scanf_s("%d", &(d1->day));

	printf("write the year: ");
	scanf_s("%d", &(d1->year));

	result = Days(&d);
	printf("result: %d", result);
}
