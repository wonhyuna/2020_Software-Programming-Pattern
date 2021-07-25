/*find the partial match in str and search using the wildcard ¡®*¡¯ */
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
		gets_s(search, sizeof(str));			//get the sentences to find the words
		if (!strcmp(search, "finish")) 
			break;								//if write the "finish", then it's end

		int i, j, count = 0, temp = 0;			//if 'temp=0' find string before '*' | if 'temp =1' find string after '*'
		
		for (j = 0; j < (int)strlen(search); j++)	//find the '*' indext of the 'search'
		{										
			if (search[j] == '*')
				break;
		}

		for (i = 0; i < (int)strlen(str); i++)				//To repeat the length of the sentence
		{ 
			if ((str[i] == search[0]) && (temp == 0)) 
			{ //when the first letter of 'search' and ith letter of 'str' is same & temp = 0
				if (!strncmp(&str[i], search, j)) 
				{ //compare 'search''s first letter and 'str''s ith letter as many as the number of characters before '*'
					temp = 1; //if 'strncmp' is not 0, then temp is 1
					i += (j - 1); //increase i by the number of 'str-1' before '*'
				}
			}
			else if ((str[i] == search[j + 1]) && (temp == 1)) 
			{ //when the letter after '*' of 'search' and ith letter of 'str' is same & temp = 1
				if (!strncmp(&str[i], &search[j + 1], strlen(search) - (j + 1))) 
				{ //compare the letter after '*' of 'search' and 'str''s ith letter as many as the number of characters after '*'
					temp = 0;//if 'strncmp' is not 0, then temp is 0
					count += 1; //increase count by 1
					i += (strlen(search) - (j + 2));//increase i by the number of 'str-1' before '*'
				}
			}
		}
		printf("count : %d\n", count); //print count
	}
}