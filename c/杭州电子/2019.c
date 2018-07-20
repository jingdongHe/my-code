#include<stdio.h>
int main()
{
	int n,m,a[100],j,k,i,b;
	scanf("%d%d",&n,&m);
	getchar();
	while(n!=0||m!=0)
	{
	  for(i=0;i<n;i++)
 	  scanf("%d",&a[i]);
	  a[i]=m;
	  for(j=0;j<=i+1;j++)
	  {
		  for(k=j+1;k<i+1;k++)
		  {
			  if(a[j]>a[k])
			  {b=a[j];a[j]=a[k];a[k]=b;}
		  }
	  }
	  for(j=0;j<=i;j++)
	  {
		  printf("%d",a[j]);
		  if(j!=i)
		  printf(" ");
		  a[j]='\0';
	  }
	  printf("\n");
	  scanf("%d%d",&n,&m);
	  getchar;
	}
	return 0;
}
