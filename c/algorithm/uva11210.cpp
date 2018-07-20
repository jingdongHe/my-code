#include<string.h>
#include<stdio.h>
const char *majiang[]={"1T","2T","3T","4T","5T","6T","7T","8T","9T",
						"1S","2S","3S","4S","5S","6S","7S","8S","9S",
						"1W","2W","3W","4W","5W","6W","7W","8W","9W",
						"DONG","NAN","XI","BEI","ZHONG","FA","BAI"};
int change(char s[])
{
	int i;
	for(i=0;i<34;i++)
	{
		if(strcmp(majiang[i],s)==0)
			return i;
	}
	return -1;
}
bool search(int pai[],int k)
{
	int i;
	for(i=0;i<34;i++)
	{
		if(pai[i]>=3)
		{
			if(k==3)
				return true;
			pai[i]-=3;
			if(search(pai,k+1)) {pai[i]+=3;return true;}
			pai[i]+=3;
		}
	}
	for(i=0;i<=24;i++)
	{
		if(i%9<=6&&pai[i]>=1&&pai[i+1]>=1&&pai[i+2]>=1)
		{
			if(k==3) return true;
			pai[i]-=1;pai[i+1]-=1;pai[i+2]-=1;
			if(search(pai,k+1)) {pai[i]+=1;pai[i+1]+=1;pai[i+2]+=1;return true;}
			pai[i]+=1;pai[i+1]+=1;pai[i+2]+=1;
		}
	}
	return false;
}
bool ok(int pai[])
{
	int i;
	for(i=0;i<34;i++)
	{
		if(pai[i]>=2)
		{
			pai[i]-=2;
			if(search(pai,0)) {pai[i]+=2;;return true;}
			pai[i]+=2;
		}
	}
	return false;
}
int main()
{
	int i,k,t=1;
	int pai[34];
	char c[5];
	while(1)
	{
		k=0;memset(pai,0,sizeof(pai));
		for(i=0;i<13;i++)
		{
			scanf("%s",&c);
			if(c[0]=='0')
				return 0;
			pai[change(c)]++;
		}
		printf("Case %d:",t++);
		for(i=0;i<34;i++)
		{
			if(pai[i]>=4)
				continue;
			pai[i]++;
			if(ok(pai))
			{
				k=1;
				printf(" %s",majiang[i]);
			}
			pai[i]--;
		}
		if(k==0)
			printf(" Not ready\n");
		else
			printf("\n");
	}
	return 0;
}