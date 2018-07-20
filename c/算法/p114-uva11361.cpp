#include<stdio.h>
#include<math.h>
int k,q[100][100][100],s;
int f(int q,int m1,int m2)
{
	int s1,s2;
	int i,j;
	if(q==0&&m1==0&&m2==0)
		return 1;
	for(i=0;i<10;i++)
		d[q][m1][m2]+=f(q-1,(m1-i+1+k)%k,k-(m2*pow(10,s-j-1)+i*pow(10,s-j-2))%k);
}
int fi(int n)
{
	int a[10];
	int i,k,j;
	int s1,s2;
	k=n;i=0;
	while(k)
		i++,k/=10;
	k=n;s=i;
	while(i>=0)
		a[--i]=k%10,k/=10;
	s1=s2=0;
	for(j=0;j<s;j++)
	{
		s1=(s1+a[j])%k,s2=(s2*10+a[j])%k;
		for(i=0;i<10;i++)
		{
			d[s-j+1][s1][s2]+=f(s-j-2,(s1-i+1+k)%k,k-(s2*pow(10,s-j-1)+i*pow(10,s-j-2))%k);
		}
	}
	return d[0][0][0];
}
int main()
{
	int a,b;
	while(scanf("%d%d%d",&a,&b,&k))
	{
		printf("%d\n",fi(a));
	}
	return 0;
}

