#include<stdio.h>
void main()
{
	//int r,s,t,i;//分别标记1角(1.8)、5角(1.5)、1元(2.0)的数量
	/*n=0.1*r+0.5*s+t;
	1.8*r==1.5*s==2*t*/
	//利用数学知识可得t=0.9r,s=1.2r,r=r;n=0.1r+0.6r+0.9r=1.6r;
	int i,n;
	float r,s,t;
	//此处由于未给出上限，故设定r<=100；
	for(i=1;i<=200;i++)
	{
		r=5*i;
		n=1.6*r;//要让n为整数，i必须为5的倍数
		s=1.2*r;
		t=0.9*r;
		if(n%10==0&&t-(int)t==0)
			printf("1角：%5.0f  5角：%5.0f  1元： %5.0f 总数： %d \n",r,s,t,n);
	}
}