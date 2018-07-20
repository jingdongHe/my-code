#include<stdio.h>
int main()
{
	char a[1000];
	int n,number,i,j;
	scanf("%d",&n);getchar();
	for(i=0;i<n;i++)
	{
		
		gets(a);
		j=0;
		number=0;
		while(a[j]!='\0')
		{
			if(a[j]>='0'&&a[j]<='9')
				number++;
			a[j]='\0';
			j++;
		}
		printf("%d\n",number);
	}
	return 0;
}

