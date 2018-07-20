#include<stdio.h>
int main()
{
	char a[100],n,i,j,d=0,k;
	while(scanf("%d",&n)!=EOF){
	getchar();
	for(j=0;j<n;j++){
	gets(a);
	k=strlen(a);
	for(i=0;i<k/2;i++)
	{
		if(a[i]==a[k-i-1])
			d++;
	}
	if(d==k/2)
		printf("yes\n");
	else
		printf("no\n");
	/*if(j!=n-1)
		printf("\n");*/
	for(i=0;i<k;i++)
		a[i]='\0';
	d=0;
	}}
	return 0;
}