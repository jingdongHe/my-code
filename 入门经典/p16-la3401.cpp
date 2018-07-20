#include<stdio.h>
#include<string.h>
int left[]={4,0,2,3,5,1};
int up[]={2,1,5,0,4,3};
char cube[4][6];
int n;
void rot(int *T,char p[])
{
	char temp[6];
	for(int i=0;i<6;i++)
		temp[i]=p[i];
	for(int i=0;i<6;i++)
		p[i]=temp[T[i]];
	//printf("%c-%c-%c-%c-%c-%c............\n",p[0],p[1],p[2],p[3],p[4],p[5]);
}
int trun(int k,char a[][6])
{
	int res=999;
	if(k>=n) 
	{
		int cnt[26]={0};
		int max=0;
		int total=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int k=++cnt[a[j][i]-'a'];
				printf("%d....\n",k);
				max=max>k?max:k;
			}
			total+=n-max;
		} 
		return total;
	}
	for(int i=0;i<6;i++)
	{
		char p[6];
		for(int s=0;s<6;s++) p[s]=a[k][s];
		if(i==0) rot(up,p);
		else if(i==1) {rot(left,p);rot(up,p);	}
		else if(i==3){rot(up,p);rot(up,p);}
		else if(i==4){rot(left,p);rot(left,p);rot(up,p);}
		else if(i==5){rot(left,p);rot(left,p);rot(left,p);rot(up,p);}
		for(int j=0;j<4;j++)
		{
			rot(left,p);
			for(int f=0;f<6;f++)
				a[k][f]=p[f];
			//printf("%c-%c-%c-%c-%c-%c\n",p[0],p[1],p[2],p[3],p[4],p[5]);
			int f=trun(k+1,a);
			res=res<f?res:f;
		}
	}
	return res;
}
int main()
{
	scanf("%d",&n);getchar();
	char a[4][6];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<6;j++)
		{
			cube[i][j]=getchar();
			a[i][j]=cube[i][j];
		}
		getchar();
	}
	printf("%d\n",trun(1,a));
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<6;j++)
			printf("%c",cube[i][j]);
		printf("\n");
	}*/
	return 0;
}
