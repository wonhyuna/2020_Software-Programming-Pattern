#include <stdio.h>

int main()
{
	int maxage = -1, minage = 1000;
	double maxscore = -1, minscore = 1000;
	int maxagecnt, minagecnt, maxscorecnt, minscorecnt;
	int age[5], maxagegrp[5], minagegrp[5];
	int score[5], maxscoregrp[5], minscoregrp[5];
	int i;

	printf("score: ");
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &score[i]);
	}
	printf("\n");
	printf("age: ");
	for (i = 0; i < 5; i++)
	{
		scanf_s("%lf", &age[i]);
	}

	for (i = 0; i < 5; i++)
	{
		if (age[i] > maxage)
		{
			maxage = age[i];
			maxagecnt = 0;
			maxagegrp[maxagecnt] = i;
		}
		else if (age[i] = maxage)
		{
			maxagecnt = maxagecnt + 1;
			maxagegrp[maxagecnt] = i;
		}
		if (age[i] < minage)
		{
			minage = age[i];
			minagecnt = 0;
			minagegrp[minagecnt] = i;
		}
		else if (age[i] = maxage)
		{
			minagecnt = minagecnt + 1;
			minagegrp[minagecnt] = i;
		}
		if (score[i] > maxscore)
		{
			maxscore = score[i];
			maxscorecnt = 0;
			maxscoregrp[maxscorecnt] = i;
		}
		else if (score[i] == maxscore)
		{
			maxscorecnt = maxscorecnt + 1;
			maxscoregrp[maxscorecnt] = i;
		}
		if (score[i] < minscore)
		{

			minscore = score[i];
			minscorecnt = 0;
			minscoregrp[minscorecnt] = i;
		}
		else if (score[i] == minscore)
		{
			minscorecnt = minscorecnt + 1;
			minscoregrp[minscorecnt] = i;
		}

	}
	for (i = 0; i <= maxagecnt; i = i + 1)
	{
		printf("score for an oldest student = %d\n", score[maxagegrp[i]]);
	}
	for (i = 0; i <= minagecnt; i = i + 1)
	{
		printf("score for an youngest student = %d\n", score[minagegrp[i]]);
	}
	for (i = 0; i <= maxscorecnt; i = i + 1)
	{
		printf("age for an highest score student = %d\n", age[maxscoregrp[i]]);
	}
	for (i = 0; i <= minscorecnt; i = i + 1)
	{
		printf("age for an lowest student = %d\n", age[minscoregrp[i]]);
	}
}
