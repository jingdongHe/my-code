#include<stdio.h>
int a[101];
void add(int x[],int y[])
{
	int i,length_x,length_y;
	int jinwei=0;
	int temp_y[100];
	for(i=0;i<100;i++)
	{
		if(x[i]==0)
			length_x=i;
		if(y[i]==0)
			length_y=i;
		temp_y[i]=y[i];
	}
	for(i=0;i<100;i++)
	{
		y[i]=x[i]+y[i]+jinwei;
		jinwei=y[i]/10;
		y[i]=y[i]%10;
	}
	for(i=0;i<100;i++)
		x[i]=temp_y[i];
}
int subcmp(int *x,int *y)
{
	int j_x,j_y,i;
	for(i=99;i>=0;i--)
	{
		if(x[i])
		{
			j_x=i;
			break;
		}
	}
	for(i=99;i>=0;i--)
	{
		if(y[i])
		{
			j_y=i;break;
		}
	}
	if(j_x>j_y)
		return 1;
	if(j_x<j_y)
		return -1;
	if(j_x==j_y)
	{
		for(i=j_x;i>=0;i--)
		{
			if(x[i]>y[i])
				return 1;
			if(x[i]<y[i])
				return -1;
		}
	}
	return 0;
}
void sub(int *x,int *y)
{
	int j_y,i;
	for(i=99;i>=0;i--)
	{
		if(x[i])
		{j_y=i;break;}
	}
	for(i=0;i<=j_y;i++)
	{
		if(x[i]>=y[i])
		{
			x[i]=x[i]-y[i];
			continue;
		}
		else
		{
			x[i]=x[i]+10-y[i];
			x[i+1]--;
		}
	}
}
void xiaoshu(int x[],int y[])
{
	int i,xx[100],yy[100],j;
	for(i=0;i<100;i++)
	{
		xx[i]=x[i];
		yy[i]=y[i];
	}
	for(i=0;i<101;i++)
	{
		if(subcmp(xx,yy)==-1)
		{
			a[i++]=0;
			for(j=99;j>=1;j--)
				xx[j]=xx[j-1];
			xx[0]=0;
		}
		while(subcmp(xx,yy)>=0)
		{
			a[i]++;
			sub(xx,yy);
		}
		for(j=99;j>=1;j--)
			xx[j]=xx[j-1];
		xx[0]=0;
	}
}
int main()
{
	int x[100]={0},y[100]={0};
	int i,b[200];
	b[0]=1;b[1]=2;
	x[0]=1;y[0]=2;
	for(i=0;i<250;i++)
		add(x,y);
	xiaoshu(x,y);
	printf("0.");
	for(i=1;i<101;i++)
	{
		printf("%d",a[i]);
		if(i%10==0)
			printf("\n");
	}
	return 0;
}