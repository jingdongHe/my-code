#include<stdio.h>
int main()
{
	char b[100];
	int k,j,a=0,e=0,i=0,o=0,u=0,n,r=0;
	scanf("%d",&n);
	getchar();
	for(k=0;k<n;k++)
	{
		gets(b);
        j=strlen(b);
		for(r=0;r<=j;r++)
		{
            if(b[r]=='a')
				a++;
			if(b[r]=='e')
				e++;
			if(b[r]=='i')
				i++;
			if(b[r]=='o')
				o++;
			if(b[r]=='u')
				u++;
		}
		for(r=0;r<=j;r++)
			b[j]='\0';
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
		if(k!=n-1)
			printf("\n");
		a=0;e=0;i=0;o=0;u=0;
		j=0;
	}
	return 0;
}
			




