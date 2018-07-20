#include<stdio.h>
void left(char a[])
{
	char c[6];
	int i;
	c[0]=a[1];c[1]=a[5];
	c[2]=a[2];c[3]=a[3];
	c[4]=a[0];c[5]=a[4];
	for(i=0;i<6;i++)
		a[i]=c[i];
}
void up(char a[])
{
	char c[6];
	int i;
	c[5]=a[2];c[0]=a[3];
	c[2]=a[0];c[3]=a[5];
	c[1]=a[1];c[4]=a[4];
	for(i=0;i<6;i++)
		a[i]=c[i];
}
void copy(char a[],char b[])
{
	int i;
	for(i=0;i<6;i++)
		b[i]=a[i];
}
void find(char a[],char b[][6])
{
	int i,d;
	char c[6];
	d=0;
	for(i=0;i<6;i++)
		c[i]=a[i];
	up(c);copy(c,b[d++]);
	for(i=0;i<3;i++)
	{
		left(c);
		copy(c,b[d++]);
	}//1在顶
	for(i=0;i<6;i++)
		c[i]=a[i];
	left(c);up(c);copy(c,b[d++]);
	for(i=0;i<3;i++)
	{
		left(c);
		copy(c,b[d++]);
	}//2在顶
	for(i=0;i<6;i++)
		c[i]=a[i];
	copy(c,b[d++]);
	for(i=0;i<3;i++)
	{
		left(c);
		copy(c,b[d++]);
	}//3在顶
	for(i=0;i<6;i++)
		c[i]=a[i];
	up(c);up(c);copy(c,b[d++]);
	for(i=0;i<3;i++)
	{
		left(c);
		copy(c,b[d++]);
	}//4在顶
	for(i=0;i<6;i++)
		c[i]=a[i];
	left(c);left(c);up(c);copy(c,b[d++]);
	for(i=0;i<3;i++)
	{
		left(c);
		copy(c,b[d++]);
	}//5在顶
	for(i=0;i<6;i++)
		c[i]=a[i];
	left(c);left(c);left(c);up(c);copy(c,b[d++]);
	for(i=0;i<3;i++)
	{
		left(c);
		copy(c,b[d++]);
	}//6在顶
}
int bijiao(char a[],char b[][6])
{
	int k=0,ans=200;
	int i,j;
	for(i=0;i<24;i++)
	{
		for(j=0;j<6;j++)
		{
			if(a[j]!=b[i][j])
				k++;
		}
		if(k<ans)
			ans=k;
		k=0;
	}
	return ans;
}
int main()
{
	char A[4][6];
	char B[24][6];
	char b1[24][6],b2[24][6],b3[24][6];
	int i,j,k=99,d;
	int n;
	scanf("%d",&n);getchar();
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
			A[i][j]=getchar();
		getchar();
	}
	find(A[0],B);
	if(n>1)
		find(A[1],b1);
	if(n>2)
		find(A[2],b2);
	if(n>3)
		find(A[3],b3);
	switch(n)
	{
	case 1:printf("0\n");break;
	case 2:for(i=0;i<24;i++)
		   {
			   d=bijiao(B[i],b1);
			   if(d<k)k=d;
		   }break;
	case 3:for(i=0;i<24;i++)
		   {
			   d=bijiao(B[i],b1)+bijiao(B[i],b2);
			   if(d<k)k=d;
		   }break;
	case 4:for(i=0;i<24;i++)
		   {
			   d=bijiao(B[i],b1)+bijiao(B[i],b2)+bijiao(B[i],b3);
			   if(d<k)k=d;
		   }break;
	}
	printf("%d\n",k);
	return 0;
}
