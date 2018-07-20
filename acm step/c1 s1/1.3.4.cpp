#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
	char name[20];
	char come[10];
	char go[10];
}record;
int main()
{
	record r, first, last;
	int N, M, i;

	scanf("%d", &N);
	for(i = 0;i < N;i++)
	{
		scanf("%d", &M);
		scanf("%s %s %s", r.name, r.come, r.go);
		first = r;
		last = r;
		while(--M)
		{
			scanf("%s %s %s", r.name, r.come,r.go);
			if(strcmp(r.come, first.come) < 0)
				first = r;
			if(strcmp(r.go, last.go) > 0)
				last = r;
		}
		printf("%s %s\n", first.name, last.name);
	}
	return 0;
}
