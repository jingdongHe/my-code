/*�κ�һ����ѧ���ԷƲ���������(Fibonacci numbers)Ӧ�ö�����İ����������������ģ�
F(1)=1;
F(2)=2;
F(n)=F(n-1)+F(n-2)(n>=3);
���ԣ�1,2,3,5,8,13�������ǷƲ��������С�
��HDOJ���в�����ص���Ŀ������1005 Fibonacci again�����������㽭ʡ���⡣
���죬��һ������Fibonacci����Ŀ�����ˣ�����һ��С��Ϸ���������£�
1��  ����һ��������Ϸ;
2��  һ����3��ʯ�ӣ������ֱ���m, n, p����
3��  ����������;
4��  ÿ��һ������ѡ������һ��ʯ�ӣ�Ȼ��ȡ��f����
5��  fֻ���ǷƲ����������е�Ԫ�أ���ÿ��ֻ��ȡ1��2��3��5��8������������
6��  ����ȡ������ʯ�ӵ���Ϊʤ�ߣ�

����˫����ʹ�����Ų��ԣ����ж����ֵ��˻�Ӯ���Ǻ��ֵ��˻�Ӯ��*/
#include<stdio.h>
#include<string.h>
int f[16],g[1010];
void fibonacci()
{
	int i;
	f[1]=1;f[2]=2;
	for(i=3;i<16;i++)
		f[i]=f[i-1]+f[i-2];
}
void G(int x)
{
	int i;
	bool vis[1010];
	g[0]=0;
	for(i=1;i<=x;i++)
	{
		memset(vis,0,sizeof(vis));
		int j;
		for(j=0;f[j]<=i;j++)
			vis[g[i-f[j]]]=1;
		for(j=0;;j++)
		{
			if(vis[j]==0)
			{g[i]=j;break;}
		}
	}
	return ;
}
int main()
{
	fibonacci();
	G(1001);
	int m,n,p;
	while(scanf("%d%d%d",&m,&n,&p)&&n&&m&&p)
	{
		m=g[m];n=g[n];p=g[p];
		int d=m^n^p;
		if(d!=0)
			printf("Fibo\n");
		else
			printf("Nacci\n");
	}
	return 0;
}