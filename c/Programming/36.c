/*һ��˼·�Ǽǵ㼯Pi = { p1, p2, ����, pi}, DiΪ�㼯Pi ����С��ΧԲ��
ע�⵽���������ǿ������õģ�
����p i ��Di-1, ��Di = Di-1, 
����i-1�������С��ΧԲDi-1�Ѿ�������µ�һ��pi������Di-1�ڲ���
��Di-1Ҳ�Ǽ����µ�����С��ΧԲ��
���� pi ������Di-1�ڲ�������С��ΧԲDi��Բ�ܱ߽�ͨ����pi ��������ǰ��i-1�����һ��Բ��������Di-1�ˡ�
��������ͨ�������������������С��ΧԲ: 
������㼯Pn����С��ΧԲMiniDisc( Pn )��
 ��ͨ����q�������˵㼯Pn�����е����С��ΧԲMiniDiscOne( Pn, q )��
 ��ͨ����q1��q2�������˵㼯Pn�����е����С��ΧԲMiniDiscTwo( Pn, q1, q2 ) ��*/
#include<stdio.h>
#include<math.h>
int x=1000,y=1000,r=0,n;
void mindisc(int a[])
{
	int i;
	for(i=0;i<n;i+=2)
	{
		if(x==1000&&y==1000)
		{
			x=a[i];y=a[i+1];
			r=0;
		}
		if(sqrt((a[i]-x)*(a[i]-x)+(a[i+1]-y)*(a[i+1]-y))<=r)
			continue;
		else
		{
			x=abs(a[i]-x)
void main()
{
	int i;
	int a[100];
	printf("please entry the number of point\n");
	scanf("%d",&n);getchar();
	for(i=0;i<n;i+=2)
		scanf("%d%d",&a[i],&a[i+1]);
}