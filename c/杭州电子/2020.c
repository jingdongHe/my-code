#include<stdio.h>
int main()
{
  int n,a[100],i,b[100],j,c;
  scanf("%d",&n);
  while(n!=0){
  for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
  for(i=0;i<n;i++)
  {	  if(a[i]<0) b[i]=-a[i];
	  else b[i]=a[i];
  }
  for(i=0;i<=n;i++)
  {
	  for(j=i+1;j<n;j++)
	  {if(b[i]<b[j]){c=b[i];b[i]=b[j];b[j]=c;c=a[i];a[i]=a[j];a[j]=c;}
	  }
  }
  for(i=0;i<n;i++)
  {
	  printf("%d",a[i]);
	  if(i!=n-1)
		  printf(" ");
	  a[i]='\0';
	  b[i]='\0';
  }
  printf("\n");
  scanf("%d",&n);
  }
  return 0;
}





