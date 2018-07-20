#include<stdio.h>
#include<string.h>
int main()
{
	char a[20],b[20];
	int a1[20]={0},b1[20]={0},c[40]={0};
	int t,la,lb,lc,i,j;
	scanf("%s",&a);scanf("%s",&b);
	la=strlen(a);lb=strlen(b);
	for(i=0;i<la;i++)//此处将两个整数拆分
		a1[i]=a[la-1-i]-48;
	for(i=0;i<lb;i++)
		b1[i]=b[lb-1-i]-48;
	/*for(i=0;i<lb;i++)
		printf("%d  ",b1[i]);
	for(i=0;i<la;i++)
		printf("%d  ",a1[i]);
	printf("\n----------------\n");*/
	t=0;
	for(i=0;i<la;i++)
	{
		for(j=0;j<lb;j++)
		{
			c[i+j]+=a1[i]*b1[j]+t;
			//if(i+j==0)printf("%d  %d",a1[0],b1[0]);printf("\n----------------\n");
			t=0;
			if(c[i+j]>9)
			{t=c[i+j]/10;c[i+j]%=10;}
		}
	}
	
	lc=la+lb;
	for(i=lc;i>=0;i--)
	{
		if(c[i]==0)
			lc--;
		if(c[i]!=0)
			break;
	}
	for(i=lc;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
	return 0;
}
