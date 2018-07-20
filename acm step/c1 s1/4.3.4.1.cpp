#include<stdio.h>
int map[9][9],num,flag;
struct stu{
 int x,y;
}p[81];
int check(int k,int cur)
{
	int i,j;
	for(i=0;i<9;i++)
		if(map[p[cur].x][i]==k||map[i][p[cur].y]==k)return 0;
	int x=p[cur].x/3*3;
	int y=p[cur].y/3*3;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(map[x+i][y+j]==k)
  		return 0;
  	return 1;
}
void dfs(int cur)
{
	 int i,j;
	if(cur==num)
	{
	 	for(i=0;i<9;i++)
	 	{
	   		for(j=0;j<8;j++)
	    		printf("%d ",map[i][j]);
	   		printf("%d\n",map[i][8]);
	  	}
	  	flag=1;
		return;
	}
 	for(i=1;i<=9;i++)
 	{
 		if(check(i,cur)&&!flag)
 		{
  			map[p[cur].x][p[cur].y]=i;
  			dfs(cur+1);
  			map[p[cur].x][p[cur].y]=0;
 		}
 	}
 	return;
}
int main()
{
 	int i,j,c=0;
 	char a[3];
	 while(scanf("%s",a)!=EOF)
 	{
  		num=0;
  		if(a[0]=='?'){p[num].x=0;p[num].y=0;num++;map[0][0]=0;}
        	else map[0][0]=a[0]-'0';
  		for(i=0;i<9;i++)
  		{
   			for(j=0;j<9;j++)
   			{
    			if(i==0&&j==0)continue;
                scanf("%s",a);
    			if(a[0]=='?')
    			{
     				map[i][j]=0;
     				p[num].x=i;
    				p[num].y=j;
     				num++;
    			}
    			else
     				map[i][j]=a[0]-'0';
   			}
  		}
  		flag=0;
  		if(c++)
  		printf("\n");
  		dfs(0);
 	}
 	return 0;
}
