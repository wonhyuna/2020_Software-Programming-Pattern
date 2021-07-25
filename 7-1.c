/*find the words in str that is the same with search.*/
#include <stdio.h>
#include <string.h>

int main() {
	char str[1000], search[1000];

	while (1) 
	{
		printf("write the sentences: ");
		gets_s(str, sizeof(str));				//get the sentences to find the words
		if (!strcmp(str, "finish"))
			break;								//if write the "finish", then it's end
		printf("write the search words: ");		
		gets_s(search, sizeof(str));			//get the words that want to find
		if (!strcmp(search, "finish"))			
			break;								//if write the "finish", then it's end

		int i, count = 0;						//initialize count to 0
		for (i = 0; i < (int)strlen(str); i++)		//To repeat the length of the sentence
		{
			if ((str[i] == search[0]))				//when search's first letter and str's first letter are the same, do the code below
			{
				if (!strncmp(&str[i], search, strlen(search)))
				{ //compare the str's ith letter and search's ith letter as the length of the search words
					count++; //if strcmp's result is 0, then increase the count by one
				}
			}
		}
		printf("count : %d\n", count);		//print count
	}
}