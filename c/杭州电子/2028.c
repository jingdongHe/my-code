#include<stdio.h>
int main()
{
	int n,a[1000],i,r,s,t,k;
	while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n-1;i++)
	{
		//printf("%d?%d.....",a[i],a[i+1]);
		r=a[i];s=a[i-1];
        if(a[i-1]>a[i])
      {
        t=a[i];
        a[i]=a[i-1];
        a[i-1]=t;
      }
      k=a[i]%a[i-1];
      while(k!=0)
      {
        a[i]=a[i-1];
        a[i-1]=k;
        k=a[i]%a[i-1];
      }
	  a[i]=(r*s)/a[i-1];
		//printf("%d?%d",a[i],a[i+1]);
	}
	printf("%d\n",a[i-1]);
	for(i=0;i<n;i++)
		a[i]='\0';
	}
	return 0;
}


	
