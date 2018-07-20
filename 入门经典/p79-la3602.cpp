#include<stdio.h>
const int maxn=1000+5;
int find_max(int count[])
{
	if(count[0]>count[1]&&count[0]>count[2]&&count[0]>count[3])
		return 0;
	else if(count[1]>count[0]&&count[1]>count[2]&&count[1]>count[3])
		return 1;
	else if(count[2]>count[1]&&count[2]>count[0]&&count[2]>count[3])
		return 2;
	else if(count[3]>count[1]&&count[3]>count[2]&&count[3]>count[0])
		return 3;
}
int main()
{
	int m,n;
	int count[4];
	char res[maxn];
	char seq[50+2][maxn];
	scanf("%d%d",&m,&n);getchar();
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%c",&seq[i][j]);
		getchar();
	}
	for(int j=0;j<n;j++)
	{
		count[0]=count[1]=count[2]=count[3]=0;
		for(int i=0;i<m;i++)
		{
			if(seq[i][j]=='A')
				count[0]++;
			else if(seq[i][j]=='C')
				count[1]++;
			else if(seq[i][j]=='G')
				count[2]++;
			else if(seq[i][j]=='T')
				count[3]++;
		}
		int k=find_max(count);
		if(k==0) res[j]='A';
		else if(k==1) res[j]='C';
		else if(k==2) res[j]='G';
		else if(k==3) res[j]='T';
	}
	for(int i=0;i<n;i++)
		printf("%c",res[i]);
	printf("\n");
	return 0;
}
