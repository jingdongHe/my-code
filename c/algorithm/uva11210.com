#include<stdio.h>
#include<string.h>
const char *majiang[]={"1T","2T","3T","4T","5T","6T","7T","8T","9T",
						"1S","2S","3S","4S","5S","6S","7S","8S","9S",
						"1W","2W","3W","4W","5W","6W","7W","8W","9W",
						"DONG","NAN","XI","BEI","ZHONG","FA","BAI"};
int change(char s[])
{
	int i;
	for(i=0;i<34;i++)
	{
		if(strcmp(s,majiang[i])==0)
			return i;
	}
	return -1;
}
int main()
{
	int pai[34]={0};
	char c[5];
	int i;
	for(i=0;i<13;i++)
	{
		gets(c);
		pai[change(c)]++;
	}
	for(i=0;i<34;i++)
		printf("%s:%d\n",majiang[i],pai[i]);
	return 0;
}