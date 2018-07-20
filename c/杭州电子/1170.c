#include<stdio.h>
int main()
{
	int k,i,a,b;
	char d;
	double m,n;
	scanf("%d",&k);
	getchar();
	for(i=0;i<k;i++)
	{
		scanf("%c%d%d",&d,&a,&b);
		getchar();
		m=(double)a;
		n=(double)b;
		switch(d)
		{
		case '+':printf("%d\n",a+b);break;
		case '-':printf("%d\n",a-b);break;
		case '*':printf("%d\n",a*b);break;
		case '/':
				if((double)(m/n)-(int)(m/n)==0)
					printf("%d\n",(int)(m/n));
				else
					printf("%.2lf\n",(double)(m/n));
				break;
		}
	}
	return 0;
}
