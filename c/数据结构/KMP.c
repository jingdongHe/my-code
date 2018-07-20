#include<stdio.h>
#include<string.h>
/*void Next(char a[],int next[])
{
	int i,j,n;
	n=strlen(a);
	i=0;j=-1;next[0]=0;next[1]=1;
	while(i<n)
	{
		if(j==-1||a[i]==a[j])
		{i++;j++;next[i]=j;}
		else
			j=next[j];
	}
}
int index(char a[],char b[],int next[])//aÖ÷´®£¬b×Ó´®
{
	int na,i=0,j=1;
	na=strlen(a);
	while(i<na&&j<=next[0])
	{
		printf("%d......%d    %c......%c\n",i,j,a[i],b[j]);
		if(j==0||a[i]==b[j-1])
		{i++;j++;}
		else
			j=next[j];
	}
	printf("\n%d......%d\n",i,j);
	if(j>next[0])
		return i-j+1;
	return 0;
}
void main()
{
	char a[]="acabaabaabcacaabc";
	char b[]="abaabc";
	int next[6],i;
	//next[0]=strlen(b);
	Next(b,next);
	for(i=0;i<6;i++)
		printf("%d ",next[i]);
	printf("\n");
	//printf("\n%d\n",index(a,b,next));
}*/
void NEXT(char a[],int next[])
{
	int n,i,j;
	n=strlen(a);
	i=0;j=-1;next[0]=-1;
	while(i<n)
	{
		if(j==-1||a[i]==a[j])
		{i++;j++;next[i]=j;}
		else
			j=next[j];
	}
	for(i=0;i<n;i++)
		printf("%d ",next[i]);
	printf("\n");
}
int index(char a[],char b[],int next[])
{
	int i,j,n_a,n_b;
	i=j=0;n_a=strlen(a);n_b=strlen(b);
	i=j=0;
	while(i<n_a&&j<n_b)
	{
		//printf("%d....%d\n%c....%c\n",i,j,a[i],b[j]);
		if(j==-1||a[i]==b[j])
		{i++;j++;}
		else
			j=next[j];
	}
	if(j==n_b)
		return i-j+1;
	return 0;
}
int main()
{
	int next[6];
	char a[]={"acabaabaabcacaabc"};
	char b[]={"abaabc"};
	puts(a);
	puts(b);
	NEXT(b,next);
	puts(b);
	printf("(%d)\n",index(a,b,next));
	printf("11111111111\n");
	return 0;
}