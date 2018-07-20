#include<stdio.h>
#include<math.h>
#include<string.h>
int change(char order[],int s,int l)
{
	int i;
	int ans=0;
	for(i=0;i<l;i++)
		ans+=ans*10+(order[i+s]-'0');
	return ans;
}
double cal(int Coe[],int Pow[],int Sig[],int k,int d)
{
	int i;
	double ans=0;
	ans+=Coe[0]*pow(k,Pow[0]);
	for(i=1;i<d;i++)
	{
		if(Sig[i-1]==0)
			ans+=Coe[i]*pow(k,Pow[i]);
		else
			ans-=Coe[i]*pow(k,Pow[i]);
	}
	return ans;
}
int main()
{
	char order[100]={'\0'};
	int Pow[20],Coe[20],Sig[20]={-1},s;
	while(gets(order))
	{
		int i,n=strlen(order),k,d=0;
		for(i=1;i<n;i++)
		{
			k=0;
			while(order[i]!='n')
			{k++;i++;}
			i++;
			Coe[d]=change(order,i-k-1,k);
			if(k==0)
				Coe[d]=1;
			if(order[i]=='^')
			{
				k=0;i++;
				while(order[i]>='0'&&order[i]<='9')
				{k++;i++;}
				if(order[i]=='+')
					Sig[d]=0;
				else
					Sig[d]=1;
				Pow[d++]=change(order,i-k,k);
			}
			if(order[i]==')')
			{Pow[d++]=1;break;}
		}
		i+=2;k=0;
		while(order[i]!='\0')
		{k++;i++;}
		s=change(order,i-k,k);
		double q;k=0;
		for(i=1;i<=Pow[0]+1;i++)
		{
			q=cal(Coe,Pow,Sig,i,d);
			if(q/s>(int)(q/s))
			{printf("Not always an integer\n");k=1;break;}
		}
		if(k==0) {printf("Alway an integer\n");continue;}
	}
	return 0;
}
			