#include<stdio.h>//此题难点在于把用平面表示的坐标，表示成立体
#define N 10
int n;
char A[6][N][N];
char B[6][N][N]={'#'};
void change(int i,int j,int k,int p,int &x,int &y,int &z)//x，y横纵坐标，z第几层
{
	if(k==0){x=p;y=j;z=i;}
	if(k==1){x=n-1-j;y=p;z=i;}
	if(k==2){x=n-1-p;y=n-1-j;z=i;}
	if(k==3){x=j;y=n-1-p;z=i;}
	if(k==4){x=n-1-i;y=j;z=p;}
	if(k==5){x=i;y=j;z=n-1-p;}
}
int main()
{
	int i,j,k,d;
	int x,y,z;
	int ans=0;
	scanf("%d",&n);getchar();
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			for(k=0;k<n;k++)
			{
				A[k][i][j]=getchar();
			}
			getchar();
		}
	}
	for(k=0;k<6;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(A[k][i][j]=='.')
				{
					for(d=0;d<n;d++)
					{
						change(k,i,j,d,x,y,z);
						B[x][y][z]='.';
					}
				}
			}
		}
	}
	while(1)
	{
		int p=1;
		for(k=0;k<6;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(A[k][i][j]!='.')
					{
						for(d=0;d<n;d++)
						{
							change(k,i,j,d,x,y,z);
							if(B[x][y][z]=='.')
								continue;
							if(B[x][y][z]=='#')
							{
								B[x][y][z]=A[k][i][j];
								break;
							}
						}
						if(B[x][y][z]==A[k][i][j])
							break;
						B[x][y][z]='.';
						p=0;
					}
				}
			}
		}
	}
	/*	if(p==1)
			break;
	}*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(B[i][j][k]!='.')
					ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
