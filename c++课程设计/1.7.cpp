/*������7. ��д����԰˻ʺ����������⣺��8��8�е������Ϸ���8���ʺ�
ʹ��һ���ʺ󶼲��ܳԵ�������7���ʺ�ע���ʺ�ɳԵ���������ͬ�л�ͬ�л�ͬһ�Խ����ϵ��������ӣ�
�����������ĳ�ַ�ʽ��ʾ������
���������磬�����������һ����ʱ�������������Ϣ����ʾ�ý�
������˱�ʾ�ڷŻʺ������λ���Լ�������״̬���� �������лʺ��λ�÷�һ����Q���ַ�������λ��Ϊ��+���ַ�����*/
#include<stdio.h>
#include<string.h>
int LineNum[9];
bool a[9], b[15], c[15];
void solve(int i, bool& ok)
{
	int k;
	if(i==8)
	{ok=true;return;}
	for(k=0;k<8;k++)
	{
		if(a[k]==true&&b[i+k-2]==true&&c[i-k+7]==true)
		{
			//printf("%d   %d\n",i,k);
			a[k]=false;b[i+k-2]=false;c[i-k+7]=false;
			LineNum[i]=k;
			solve(i+1,ok);
			if(ok==true) return;
			a[k]=true;b[i+k-2]=true;c[i-k+7]=true;
		}
	}
}
int main()
{
	bool ok=false;
	memset(a,true,sizeof(a));
	memset(b,true,sizeof(b));
	memset(c,true,sizeof(c));
	char map[8][8];int i,j;
	memset(map,'+',sizeof(map));
	solve(0,ok);
	for(i=0;i<8;i++)
		map[i][LineNum[i]]='Q';
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
	return 0;
}