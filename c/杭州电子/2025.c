#include<stdio.h>
int main()
{
	char a[100],max;
	int k,i;
	
	while(gets(a))
	{
		k=strlen(a);
		max=a[0];
		for(i=0;i<k;i++)
		{
			if(a[i]>max)
				max=a[i];
		}
		for(i=0;i<k;i++)
		{
			printf("%c",a[i]);
			if(a[i]==max)
				printf("(max)");
			a[i]='\0';
		}
		printf("\n");
	}
	return 0;
}

	