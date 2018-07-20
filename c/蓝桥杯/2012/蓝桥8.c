#include<stdio.h>
#include<string.h>
int suo(int a);
int suo(int a)
{
	int n=0,i;
	while(a>0)
	{
		i=a%10;
		//printf("%d  i\n",i);
		a=a/10;
		n+=i;
		//printf("%d  a\n",a);
	}
	if(n>9)
		n=suo(n);
	return n;
}
		
int main()
{
	char a[101];
	int d,b[6]={0},i,p,n;
	scanf("%d",&n);
	while(n--)
	{
		gets(a);
		d=strlen(a);//以证明输入完全正确
		for(i=0;i<d;i++)
		{
			p=i%6;//已证p的值正确
			switch(p)//已证switch格式正确
			{
			case 0:b[p]+=a[i];break;
			case 1:b[p]+=a[i];break;
			case 2:b[p]+=a[i];break;
			case 3:b[p]+=a[i];break;
			case 4:b[p]+=a[i];break;
			case 5:b[p]+=a[i];break;
			}
		}
		for(i=0;i<6;i++)
		{
			if(b[i]>9)
				b[i]=suo(b[i]);
			printf("%d",b[i]);
		}
		for(i=0;i<6;i++)
			b[i]=0;
		for(i=0;i<d;i++)
			a[i]=0;
		printf("\n");
	}
	return 0;
}
