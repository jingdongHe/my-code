#include<stdio.h>
#define max 100
typedef struct 
{
	int data[max];
	int top;
}stack;
stack Stackinit()
{
	stack s;
	s.top=-1;
	return s;
}
stack push(stack s,int x)
{
	if(s.top==max-1)
	{
		printf("full\n");
		return s;
	}
	s.top++;
	s.data[s.top]=x;
	return s;
}
int stacklength(stack s)
{
	return s.top+1;
}
void main()
{
	stack s;
	s=Stackinit();
	s=push(s,1);
	s=push(s,2);
	s=push(s,3);
	printf("%d",stacklength(s));
}