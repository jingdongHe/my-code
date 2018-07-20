#include<stdio.h>
int main()
{
	int a[8][8]={0},d=0,i=0,j=0,r1,r2,s1,s2,a1,a2,b1,b2,k,t=0,x,y;

	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(a[i][j]==0)
			{d++;
			a[i][j]=1;
			for(k=0;k<8;k++)
				a[i][k]=1;
			for(k=0;k<8;k++)
				a[k][j]=1;
			while(r1<8&&s1<8)
			{a[r1][s1]=1;r1++;s1++;}
			while(a1>0&&b1>0)
			{a[a1][b1]=1;a1--;b1--;}
			while(r2>0&&s2<8)
			{a[r2][s2]=1;r2--;s2++;}
			while(a2<8&&b2>0)
			{a[a2][b2]=1;a2++;b2--;}
			}	
		}
		if(d==8)
			t++;
		d=0;
		for(x=0;x<8;x++)
			for(y=0;y<8;y++)
				a[x][y]=0;
	}
		printf("%d",t);
		t=0;
		return 0;
}
