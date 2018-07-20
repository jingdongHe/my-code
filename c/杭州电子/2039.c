#include<stdio.h>
#include<math.h>
int main()
{
	int m,i,k;
	float a,b,c;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%f%f%f",&a,&b,&c);
	k=0;
	if(a+b>c&&a+c>b&&b+c>a)
		k++;
	if(fabs(a-b)<c&&fabs(a-c)<b&&fabs(b-c)<a)
		k++;
	if(k==2)
		printf("YES\n");
	else
		printf("NO\n");}
	return 0;
}
		