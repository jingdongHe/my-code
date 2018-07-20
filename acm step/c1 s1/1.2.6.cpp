#include<stdio.h>
int main()
{
	int a,b;
	char ch;
	int n;
	scanf("%d",&n);getchar();
	for(int i=0;i<n;i++)
	{
		ch=getchar();getchar();
		scanf("%d",&a);getchar();
		scanf("%d",&b);getchar();
		switch(ch)
		{
			case '+':printf("%d\n",a+b);break;
			case '-':printf("%d\n",a-b);break;
			case '*':printf("%d\n",a*b);break;
			case '/':double k=a*1.0/b;int s=a*1.0/b;
					if(k-s==0) printf("%d\n",s); 
					else printf("%.2lf\n",k);break;
			//case '/':double k=a*1.0/b;int s=k*1000;int f=s%10;if(f>=5) k+=0.01;printf("%.2lf\n",k);break;
		}
	}
	return 0;
}
