/*题目16：2003年突发的非典型肺炎（SARS）是一种病源还不完全了解的新型传染病，需要隔离所有疑似病例。
在N大学，有许多学生团体，一个学生可以加入多个团体，同一个学生团体内部成员被认为是经常接触的。
N大学为了应付SARS，规定若一个学生被认为是疑似病例，则他所在团体的所有学生都被认为是疑似病例。
现在需要你编写一个程序，在发现一个学生是疑似病例后，找到所有与之直接或间接接触过的疑似病例。
可以设每一名学生用数字0到n-1编号，输入有学生总数n, 学生团体数k，每个学生团体的人数和成员的编号，
可能是SARS疑似病例的学生编号，输出所有找到的疑似病例学生编号。例如，输入数据如下：
100 4  //100名学生，4个学生团体；
2 1 2   //第一个学生团体有2人，是编号1和2的两位学生，以下三个团体类似； 
5 10 13 11 12 14
2 0 1
2 99 2
0      //现在发现编号0的学生是疑似病例。
这时应输出如下：
4，0，1，2，99 表示发现有4位疑似病例，是编号是0，1，2，99的四位。*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int org[10][200];//定义一个布尔型数组，来表示学生和社团之间的关系
int n,k;//n，k定义学生数和社团数
void input()
{
	int i,r,s,t;
	//memset(org,0,sizeof(org));//初始化数组
	printf("请输入学生数和社团数\n");
	scanf("%d%d",&n,&k);getchar();
	for(i=0;i<k;i++)
	{
			printf("请输入第%d个社团有多少学生\n",i+1);
			scanf("%d",&s);getchar();
			for(r=0;r<s;r++)
			{
				printf("请输入第%d个学生的学号\n",r+1);
				scanf("%d",&t);getchar();
				org[i][t]=1;
			}
	}
	/*for(i=0;i<k;i++)
	{
		for(r=0;r<n;r++)
		{
			printf("%d ",org[i][r]);
		}
		printf("\n");
	}*/
}
int ex(int a[],int j,int k)
{
	int i;
	for(i=0;i<j;i++)
	{
		if(a[i]==k)
			return 1;
	}
	return 0;
}
void chact(int q)
{
	int i;
	int ia,ja,ib,jb;//用i，j来控制数组的压人及弹出，此处为节省时间没有按照标准的队写
	int a[100],b[10];//定义a为疑似感染学生的学号，b为学生参加的社团的编号
	int s;
	ia=ja=ib=jb=0;
	a[ia++]=q;
	q=a[ja++];
	for(i=0;i<k;i++)
	{
		if(org[i][q]==1)
			b[ib++]=i;
	}
	printf("%d ",q);
	while(ib!=jb)
	{
		//printf("%d.....%d,,,,,,,%d,,,,,,,,,,%d\n",ia,ja,ib,jb);
		if(ib==jb)
			break;
		s=b[jb++];
		for(i=0;i<n;i++)
		{
			if(org[s][i]==1&&ex(a,ja,i)==0)
				a[ia++]=i;
		}
		q=a[ja++];
		for(i=0;i<k;i++)
		{
			if(org[i][q]==1&&ex(b,jb,i)==0)
				b[ib++]=i;
		}
		
		printf("%d ",q);
	}
}
void main()
{
	int q;
	input();
	printf("请输入疑似学生的学号\n");
	scanf("%d",&q);getchar();
	chact(q);
}

