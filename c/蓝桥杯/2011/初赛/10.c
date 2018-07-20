#include<stdio.h>
char a[5][5];//密钥单词方阵
char b[26]="youandme";//存储密钥单词
char c[51]="welcometohangzhou";//存储待加密字符串
char d[51];//加密结果
void b_square()
{
	int i,j,k=0,r=0;
	char d='a';
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			a[i][j]=b[k++];
			if(b[k]=='\0')
				break;
		}
		if(b[k]=='\0')
			break;
	}//此处循环结束后k已经为字符串长度
	i=k/5;j=k%5;
	while(1)
	{
		for(r=0;r<k;r++)
		{
			if(b[r]==d)
			{
				d++;
				break;
			}
		}
		if(r!=k)
			continue;
		a[i][j]=d;
		d++;
		j++;
		if(j==5)
		{
			i++;j=0;
		}
		if(i==5&&j==0)
			break;
	}
	return;
}
void encryp()
{
	int k=0,i1=6,j1=6,i2=6,j2=6,i,j;
	//c[k],c[k+1]
	while(c[k]!='\0')
	{
		i1=6;j1=6;i2=6;j2=6;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(a[i][j]==c[k])
				{i1=i;j1=j;}
				if(a[i][j]==c[k+1])
				{i2=i;j2=j;}
			}
		}
		if((i1==6&&j1==6)||(i2==6&&j2==6))
		{d[k]=c[k];d[k+1]=c[k+1];k+=2;continue;}
		if(i1==i2&&j1==j2)
		{d[k]=c[k];d[k+1]=c[k+1];k+=2;continue;}
		if(i1==i2||j1==j2)
		{d[k]=c[k+1];d[k+1]=c[k];k+=2;continue;}
		if(c[k+1]=='\0')
		{d[k]=c[k];k+=2;break;}
		d[k]=a[i1][j2];d[k+1]=a[i2][j1];k+=2;
	}
	return;
}
void main()
{
	int i,j;
	/*printf("Please entry the key word\n");
	gets(b);
	puts(b);
	printf("Please entry the string\n");
	gets(c);*/
	b_square();
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%2c",a[i][j]);
		printf("\n");
	}
	encryp();
	i=0;
	while(d[i]!='\0')
	{printf("%c",d[i]);i++;}
	printf("\n");
	return;
}