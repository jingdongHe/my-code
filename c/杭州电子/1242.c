#include<stdio.h>
char map[200][200]={"#.#####.","#.a#..r.","#..#x...","..#..#.#","#...##..",".#......","........"};
int k[200][200];





int m,n,z=15;
int movex[]={0,0,-1,1},movey[]={-1,1,0,0};
int ok(int sx,int sy,int k)
{
	if(sx>=0&&sx<m&&sy>=0&&sy<n&&k<z)
		return 1;
	return 0;
}
void dfs(int sx,int sy,int k)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(ok(sx+movex[i],sy+movey[i],k))
		{
			k++;
			if(map[sx+movex[i]][sy+movey[i]]=='x')
				k++;
			if(map[sx+movex[i]][sy+movey[i]]=='f')
			{
				if(k<z)
					z=k;
				return ;
			}
			printf("%d\n",k);
			map[sx+movex[i]][sy+movey[i]]='#';
			dfs(sx+movex[i],sy+movey[i],k);
			map[sx+movex[i]][sy+movey[i]]='.';
		}
	}
	return ;
}
int main()
{
	int i,j;
	int sx,sy;
	/*scanf("%d%d",&n,&m);
	
		for(j=0;j<n;j++)
		{
			scanf("%s",&map[j]);
			getchar();
		}*/
	n=7;m=8;
		for(j=0;j<n;j++)
			for(i=0;i<m;i++)
			{
				if(map[j][i]=='a')
				{sx=i;sy=j;}
			}
		dfs(sx,sy,0);
		//printf("%d\n",k);
		if(z==15)
			printf("The anger is ded\n");
		else
			printf("%d",z);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				map[i][j]='\0';
	
	return 0;
}
		
