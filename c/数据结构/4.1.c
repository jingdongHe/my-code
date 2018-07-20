#include<stdio.h>
#include<string.h>
int find(char *a,char *b)
{
	int na,nb,i,j;
	na=strlen(a);
	nb=strlen(b);
	i=j=0;
	while(i<na&&j<nb)
	{
		//printf("%d.....%d\n(%c......%c)\n",i,j,a[i],b[j]);
		if(a[i]==b[j])
		{i++;j++;}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j==nb)
	{
		return i-j+1;
	}
	return 0;
}
void main()
{
	char a[]="12356789";
	char b[]="56789";
	printf("%d\n",find(a,b));
}
