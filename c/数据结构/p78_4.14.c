#include<stdio.h>
#include<string.h>
void time(char a[],char b[])
{
	int i,j,na,nb,k=0;
	na=strlen(a);
	nb=strlen(b);
	//printf("[%d]\n",na);
	for(i=0;i<na;i++)
	{
		j=0;
		//printf("%d\n",i);
		while(a[i]==b[j]&&a[i]!='\0'&&b[j]!='\0')
		{
			//printf("%d:%c.....%c\n",i,a[i],b[j]);
			i++;j++;
		}
		if(j==nb)
		{k++;}
		i=i-j;
	}
	printf("(%d)\n",k);
}
void main()
{
	char a[81]="1234567856790567989567",b[81]="567";
	time(a,b);
}