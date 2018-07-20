#include<stdio.h>
#include<string.h>
const char pai[][6]={"1t","2t","3t","4t","5t","6t","7t","8t","9t",
				"1s","2s","3s","4s","5s","6s","7s","8s","9s",
				"1w","2w","3w","4w","5w","6w","7w","8w","9w",
				"dong","nan","xi","bei","zhong","fa","bai"};
int find(char a[])
{
	int i;
	for(i=0;i<34;i++)
	{
		if(strcmp(pai[i],a)==0)
			return i;
	}
	return -1;
}
int search(int a[],int h)
{
	int i;
	for(i=0;i<34;i++)
	{
		if(a[i]>=3)
		{
			if(h==3)
				return 1;
			a[i]-=3;
			if(search(a,h+1))
				return 1;
			a[i]+=3;
		}
	}
	for(i=0;i<24;i++)
	{
		if(i%9<=6&&a[i]>=1&&a[i+1]>=1&&a[i+2]>=1)
		{
			if(h==3)return 1;
			a[i]--;a[i+1]--;a[i+2]--;
			if(search(a,h+1)==1)return 1;
			a[i]++;a[i+1]++;a[i+2]++;
		}
	}
	return 0;
}
int check(int a[])
{
	int i;
	for(i=0;i<34;i++)
	{
		if(a[i]>=2)
		{
			a[i]-=2;
			if(search(a,0)==1)
				return 1;
			a[i]+=2;
		}
	}
	return 0;
}
int main()
{
	int i,j,d,k=0;
	int a[34]={0};
	int c[34]={0};
	char s[6];
	for(i=0;i<13;i++)
	{
		scanf("%s",&s);
		d=find(s);
		a[d]++;
	}
	for(i=0;i<34;i++)
	{
		if(a[i]>=4)
			continue;
		for(j=0;j<34;j++)
			c[j]=a[j];
		c[i]++;
		if(check(c)==1)
		{
			k=1;
			printf("%s\n",pai[i]);
		}
	}
	if(k==0)
		printf("not ready\n");
	return 0;
}

