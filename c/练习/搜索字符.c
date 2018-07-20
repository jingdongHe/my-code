#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char string[100];
	int a[27]={0};
	char b[27];
	int i,j,k=0,n;
	printf("Please entry the string:\n");
	gets(string);
	n=strlen(string);
	for(i=0;i<n;i++)
		string[i]=tolower(string[i]);
	for(i=0;i<n;i++)
	{
		if(string=='\0')
			continue;
		if(string[i]>='a'&&string[i]<='z')
		{
			a[i]=1;k++;
			for(j=i+1;j<n;j++)
			{
				if(string[i]==string[j])
				{
					a[i]++;
					string[j]='\0';
					k++;
				}
			}
			b[i]=string[i];
		}
	}
	a[26]=n-k;
	for(i=0;i<26;i++)
	{
		if(b[i]!='\0'&&a[i]!=0)
			printf("%c:%d\n",b[i],a[i]);
	}
	printf("else:%d\n",a[26]);
	return 0;
}
