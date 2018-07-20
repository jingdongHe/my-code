/*[28] Auther1, Auther2, “Paper name one”, Magazine1, August 1983.
You and me, [15] and [28]; Me and you,[28] and [15].
[15] Auther1, Auther2, Auther3, “Paper name two” ,Magazine1, August 1983.
这时应该得到的输出数据是：
You and me, [1] and [2]; Me and you,[2] and [1].
[1] Auther1, Auther2, “Paper name one”, Magazine1, August 1983.
[2] Auther1, Auther2, Auther3, “Paper name two” ,Magazine1, August 1983.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[10][100];
char b[10][10];//用于标记
char s1(int j,int i)
{
	int k,r,d=0,q=j;
	for(r=1;r<=3;r++)
	{
		j=q;d=0;
		k=strlen(b[r]);
		while(a[i][j++]==b[r][d++]);
		if(j-q-1==k)
			return r+'0';
	}
	return 0;
}
void main()
{
	int i=0,j,r,s,k,d1;
	char c[10][100];
	
	char d=1;
	memset(a,'\0',sizeof(a));memset(b,'\0',sizeof(b));memset(c,'\0',sizeof(c));
	strcpy(a[0],"[28] Auther1, Auther2, “Paper name one”, Magazine1, August 1983.");
	strcpy(a[1],"You and me, [15] and [28]; Me and you,[28] and [15].");
	strcpy(a[2],"[15] Auther1, Auther2, Auther3, “Paper name two” ,Magazine1, August 1983.");
	for(i=0;i<3;i++)
	{
		j=0;r=s=0;k=0;
		while(a[i][j]!='\0')//可得出[]内的数
		{
			if(a[i][j]=='[')
				r=j;
			if(a[i][j]==']')
				s=j;
			if(s!=0&&r!=0)
				break;
			j++;
		}
		for(j=r;j<=s;j++)
		{
			
			b[d][k++]=a[i][j];
		}
		k=0;
		d++;
	}
	for(i=0;i<3;i++)
	{
		j=0;d1=0;
		while(a[i][j]!='\0')
		{
			if(a[i][j]=='[')
			{
				
				c[i][d1++]='[';
				c[i][d1++]=s1(j,i);
				c[i][d1++]=']';
				while(a[i][j++]!=']');
			}
			else
				c[i][d1++]=a[i][j];
			j++;
		}
	}
	for(i=0;i<3;i++)
		puts(c[i]);
//	free(c);
}