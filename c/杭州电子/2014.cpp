#include<stdio.h>
int main()
{
    int i,n;
    double a[100],max,min,d=0,p;
    while(scanf("%d",&n)!=EOF){
	if(n>2&&n<=100) {
    for(i=0;i<n;i++)
      scanf("%lf",&a[i]);
	max=a[0];min=a[0];
	for(i=0;i<n;i++)
	{
      d=d+a[i];
      if(a[i]>max)
      max=a[i];
     }
	for(i=0;i<n;i++)
	{
	  if(min>a[i])
      min=a[i];
	}
     p=(d-max-min)/(n-2);
     printf("%.2lf\n",p);d=0;}}
     return 0;
}
