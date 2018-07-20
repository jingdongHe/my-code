#include<stdio.h>
int main()
{
	int n,i,j=1,k=0;
	char a[50];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(a);
		k=0;j=1;
        if(a[0]>='0'&&a[0]<='9')
			k++;
		while(a[j]!='\0')
		{
			if((a[j]>='a'&&a[j]<='z')||(a[j]>='A'&&a[j]<='Z')||(a[j]>='0'&&a[j]<='9')||(a[j]=='_'))
				k=k;
			else
				k++;
			a[j]='\0';
			j++;
		}
		if(k!=0)
			printf("no\n");
		else
			printf("yes\n");
		k=0;j=1;
	}
	return 0;
}

