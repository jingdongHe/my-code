/*������4. �û��²����λ�ã��������n��n�У��к�Ϊ0��n-1���к�Ϊ0��n-1��
�ġ����̡���ĳһλ�ô����ط�һ�����������λ��ͨ��ʹ�á�rand()%10���������������
�û�ͨ���������к�����Ѱ�ҡ��������
��û�¶�ʱ�����Ҫ�����û���ط������λ���ж�Զ��ȡ����Ľ��ƾ��룩��*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void Set(int n,int &x,int &y)
{
	srand(time(NULL));
	x=rand()%n;y=rand()%n;
}
void Find(int x,int y)
{
	int a,b;
	printf("Please entry the point set\n");
	scanf("%d%d",&a,&b);
	if(a==x&&b==y)
		printf("It is the point\n");
	else
		printf("It isn't the point,the distance is %d\n",(int)sqrt((a-x)*(a-x)+(b-y)*(b-y)));
}
int main()
{
	int n;
	int x,y;
	scanf("%d",&n);
	Set(n,x,y);
	printf("\"The point is (%d,%d)\"\n",x,y);
	Find(x,y);
	return 0;
}
