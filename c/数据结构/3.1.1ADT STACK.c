#include<stdio.h>
#define max 100
typedef struct 
{
	int data[max];
	int p;
}seqstack;
seqstack stackinit()
{
	seqstack s;
	s.p=-1;
	return s;
}
int stackempty(seqstack s)
{
	if(s.p==-1)
		return 1;
	else
		return 0;
}
void push(seqstack s,int x)
{
	if(s.p==max-1)
	{
		printf("full\n");
		return ;
	}
	s.p++;
	s.data[s.p]=x;
	return ;
}
int Pop(seqstack s)
{
	int x;
	if(s.p==-1)
	{
		printf("empty\n");
		return -1;
	}
	x=s.data[s.p];
	s.p--;
	return x;
}
int Stackgettpo(sqestack s)
{
	if(s.p!=-1)
		return s.data[s.p];
	return;
}
void stackclear(sqestack s)
{
	s.p=-1;
}
int stacklength(sqestack s)
{
	return s.p+1;
}
void main()
{
	sqestack s;
	s=stackinint();
	printf("%d\n",stackempty(s));
	push(s,1);
	push(s,2);
	push(s,3);
	printf("%d\n",Pop(s));
	printf("%d\n",stackempty(s));
	printf("%d\n",stackgettop(s));
	printf("%d\n",stacklength(s));
	stackclear(s);
	printf("%d\n",stackempty(s));
}
