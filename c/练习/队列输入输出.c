#include<stdio.h>
#include<math.h>
#define n 4
int i=-1,j=-1;//iΪͷָ��
int a[n]={'\0'};
void enqueue()//¼�����Ԫ��
{	
	j=(j+1)%n;
	if(j==i)
		printf("full\n");
	else
	{
		printf("please entry number:\n");
		scanf("%d",&a[j]);
	}
}
/*	if(j==n&&abs(j-i)+1!=n)
		j=j%(n-1);
	if(i==j)
	{
		printf("sorry there is not enough blank\n");
	}
	else
	{
		printf("please entry number:\n");
		scanf("%d",&a[j]);
		j++;
	}

}*/
void dequeue()//ɾ������Ԫ��
{
	i=(i+1)%n;
	a[i]='\0';
}
void front()
{
	if(i==j)
	{
		if(a[i-1]!='\0')
			printf("%d\n",a[i]);
		else
			printf("empty\n");
	}
	else
		printf("%d\n",a[i+1]);
}
void output()
{
	int k;
	if(i==j&&a[i-1]=='\0')
		printf("emtpy");
	else
	{
		for(k=0;k<n;k++)
		{
			if(a[k]!='\0')
				printf("%d ",a[k]);
		}
	}
	printf("\n");
}
int main()
{
	enqueue();
	enqueue();
	enqueue();
	output();
	dequeue();
	dequeue();
	output();
	enqueue();
	enqueue();
	front();
	output();
	return 0;
}
