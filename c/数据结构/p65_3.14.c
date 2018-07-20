#include<stdio.h>
#define n 10
typedef struct 
{
	int d[n];
	int ph,pr;
}stack;
stack Stackinit()
{
	stack s;
	s.ph=-1;
	s.pr=n;
	return s;
}
stack Push(stack s,int i,int x)
{
	if(s.ph>=s.pr)
	{
		printf("full\n");
		return s;
	}
	if(i==0)
	{
		s.ph++;
		s.d[s.ph]=x;
	}
	if(i==1)
	{
		s.pr++;
		s.d[s.pr]=x;
	}
	return s;
}
stack Pop(stack s,int i)
{
	if(i==0)
	{
		if(s.ph==-1)
		{
			printf("enpty\n");
			return s;
		}
		printf("%d\n",s.d[s.ph]);
		s.ph--;
	}
	if(i==1)
	{
		if(s.pr==n)
		{
			printf("empty\n");
			return s;
		}
		printf("%d\n",s.d[s.pr]);
		s.pr++;
	}
	return s;
}
void main()
{
	stack s;
	s=Stackinit();
	s=Push(s,0,1);
	s=Push(s,0,2);
	s=Push(s,1,3);
	s=Push(s,1,4);
	s=Pop(s,0);
	s=Pop(s,1);
}