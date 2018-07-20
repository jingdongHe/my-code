#include<stdio.h>
struct node
{
	int number;
	char name[20];
}s;
int main()
{
	scanf("%d%s",&s.number,&s.name);
	printf("%d\n%s\n",s.number,s.name);
	return 0;
}
