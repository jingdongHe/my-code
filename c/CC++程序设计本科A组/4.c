#include<stdio.h>
#include<math.h>
int dao(int k)
{
	int a[4];
	int d=3,s=0;
	while(k!=0)
	{
		a[d--]=k%10;
		k=k/10;
	}
	for(d=3;d>=0;d--)
	{
		if(a[d]==9)
		{
			s+=6*pow(10,d);
			continue;
		}
		if(a[d]==6)
		{
			s+=9*pow(10,d);
			continue;
		}
		s+=a[d]*pow(10,d);
	}
	return s;
}
int main()//标价都是4位数
{
	//只有1‘2’5‘6’8‘9’0‘可倒过来看
	//    1’2‘5’9‘8’6‘0’
	int a,b,c,d;
	int earn[100],com[100];
	int Earn,Com;
	int i=0,j=0;
	int k,s;
	for(a=1;a<=9;a++)
	{
		if(a==3||a==4||a==7)
			continue;
		for(b=0;b<=9;b++)
		{
			if(b==3||b==4||b==7)
				continue;
			for(c=0;c<=9;c++)
			{
				if(c==3||c==4||c==7)
					continue;
				for(d=1;d<=9;d++)
				{
					if(d==3||d==4||d==7)
						continue;
					k=a*1000+b*100+c*10+d;
					s=dao(k);
					if((s-k)/100==8)
					{
						//printf("%d-%d=%d\n",s,k,s-k);
						earn[i++]=k;
					}
					if((k-s)/100==2)
					{
						//printf("%d-%d=%d\n",s,k,s-k);
						com[j++]=k;
					}
				}
			}
		}
	}
	for(a=0;a<i;a++)
	{
		for(b=0;b<j;b++)
		{
			Earn=dao(earn[a])-earn[a];
			Com=com[b]-dao(com[b]);
			//printf("%d..........%d............%d..........%d,,,,,,,%d\n",earn[a],com[b],Earn,Com,Earn-Com);
			if(Earn-Com==558)
				printf("%d........%d\n",earn[a],com[b]);
		}
	}
/*	for(d=0;d<i;d++)
		printf("%d ",earn[d]);
	printf("\n");
	for(d=0;d<j;d++)
		printf("%d ",com[d]);
	printf("\n");*/
	return 0;
}
