#include<stdio.h>
#include<math.h>
int main()
{
    float x1,y1,x2,y2,x,y;
	float s;
    while(scanf("%f%f%f%f",&x1,&y1,&x2,&y2)!=EOF)
	{x=x1-x2;y=y1-y2;s=x*x+y*y;
	//printf("%d%d",x,y);
    printf("%0.2f\n",sqrt(s));}
    return 0;
}
    
