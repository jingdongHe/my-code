#include<stdio.h>
#include<string.h>
int main()
{
	char a[10000]={'\0'}; 
	//char a[]={'A','B','B','C','C','C'};
	int n,i,j,d,b[24];
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			gets(a);
			d=strlen(a);
			for(i=0;i<24;i++)
				b[i]=1;
			for(i=0;i<d;i++)
			{
				for(j=i+1;j<d+1;j++)
				{
					if(a[i]==a[j])
					{b[i]++;a[j]='\0';}
				}
			}
			for(i=0;i<d;i++)
			{
				if(a[i]!='\0')
				{
					if(b[i]!=1)
						printf("%d",b[i]);
					printf("%c",a[i]);
				}
			}
			printf("\n");
			for(i=0;i<d;i++)
			{a[i]='\0';b[i]=1;}
		}
	}
	return 0;
}



