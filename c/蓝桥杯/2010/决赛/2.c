#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int i,len;
	char* p = "abcdef";
	char* q = (char*)malloc(strlen(p)+1); 
	len=strlen(p);
	for(i=0; i<len-1; i++)
        q[len-i-2] = p[i+1];
	q[len-1] = p[0];
	q[len]='\0';
	printf("%s\n", q);free(p);
}
