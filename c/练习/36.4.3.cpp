#include<stdio.h>
int main()
{
    int a[3],i,n,j,d;
    
    for(i=0;i<3;i++)
    scanf("%d",&a[i]);
    for(i=0;i<3;i++)
    {
      for(j=i+1;j<3;j++){
      if(a[i]<a[i+1]){d=a[i];a[i]=a[i+1];a[i+1]=d;}}}
    for(i=0;i<3;i++)
    printf("%d ",a[i]);
}
