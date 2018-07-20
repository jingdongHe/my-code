#include<stdio.h>
#include<string.h>
//此题由于没有线性关系，故不能dfs
int a[3][3];
void output()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("---------------\n");
}
void build()//i从8开始
{
	int i1,i2,i3,i4,i5,i6,i7;
	int b[9]={0};
	for(i1=8;i1>=6;i1--)
	{
		if(b[i1]==0)
			a[0][1]=i1;
		else
			continue;
		b[i1]=1;
		for(i2=7;i2>=3;i2--)
		{
			if(b[i2]==0&&(a[0][1]!=0&&i2<a[0][1]))
				a[0][2]=i2;
			else
				continue;
			b[i2]=1;
			for(i3=8;i3>=6;i3--)
			{
				if(b[i3]==0)
					a[1][0]=i3;
				else
					continue;
				b[i3]=1;
				for(i4=8;i4>=4;i4--)
				{
					if(b[i4]==0&&(a[0][1]!=0&&i4<a[0][1])&&(a[1][0]!=0&&a[1][0]>i4))
						a[1][1]=i4;
					else
						continue;
					b[i4]=1;
					for(i5=8;i5>=2;i5--)
					{
						if(b[i5]==0&&(a[1][1]!=0&&a[1][1]>i5)&&(a[0][2]!=0&&i5<a[0][2]))
							a[1][2]=i5;
						else
							continue;
						b[i5]=1;
						for(i6=8;i6>=3;i6--)
						{
							if(b[i6]==0&&(a[1][0]!=0&&i6<a[1][0]))
								a[2][0]=i6;
							else
								continue;
							b[i6]=1;
							for(i7=8;i7>=2;i7--)
							{
								if(b[i7]==0&&(a[1][1]!=0&&i7<a[1][1])&&(a[2][0]!=0&&i7<a[2][0]))
									a[2][1]=i7;
								else
									continue;
								b[i7]=1;
								output();
								b[i7]=0;
							}
							b[i6]=0;
						}
						b[i5]=0;
					}
					b[i4]=0;
				}
				b[i3]=0;
			}
			b[i2]=0;
		}
		b[i1]=0;
	}
}
void main()
{
	memset(a,0,sizeof(a));
	a[0][0]=9;
	a[2][2]=1;
	build();
	
}