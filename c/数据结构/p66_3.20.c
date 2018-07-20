#include<stdio.h>
#define n 5
typedef struct 
{
	int data[n];
	int p;
}stack;
stack Stackinit()
{
	stack s;
	s.p=-1;
	return s;
}
stack push(stack s,int x)
{
	if(s.p==n-1)
	{
		printf("full\n");
		return s;
	}
	s.p++;
	s.data[s.p]=x;
	return s;
}
stack pop(stack s)
{
	if(s.p==-1)
	{
		printf("empty\n");
		return s;
	}
	printf("%d\n",s.data[s.p]);
	s.p--;
	return s;
}
int sempty(stack s)
{
	if(s.p==-1)
		return 1;
	return 0;
}
void main()
{
	stack s;
	s=Stackinit();
	s=push(s,1);
	s=push(s,2);
	s=pop(s);
}