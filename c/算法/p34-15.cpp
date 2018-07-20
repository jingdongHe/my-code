#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int point;
	struct node *next;
}node;
int po[1000];
int pr[1000];
node w[1000];
int n,s,k,q;
bool visit(int d)
{
	node *p;
	p=&w[d];
	p=p->next;
	while(p!=NULL)
	{
		if(po[p->point]==0)
			return true;
		p=p->next;
	}
	return false;
}
void DFS(int d,int k1)
{
	node *p;
	if(po[d]==1||k1>k)
		return ;//������Χ
	if(k1==k&&w[d].next!=NULL&&visit(d))
	{
		q=d;return;

	}//�ҳ��µ�����
	
	po[d]=1;
	p=&w[d];p=p->next;
	while(p!=NULL)
	{
		DFS(p->point,k1+1);
		p=p->next;
	}
	return ;
}
void deep(int d,int k1)
{
	if(pr[d]==1)
	{
		return;
	}
	if(q<k1)
		q=k1;
	pr[d]=1;
	node *p;
	p=&w[d];
	p=p->next;
	while(p!=NULL)
	{
		deep(p->point,k1+1);
		p=p->next;
	}
	return;
}
void insert(int d,int a,int k1)
{
	node *p;
	if(pr[d]==1||k1>a)
		return ;//������Χ
	if(k1==a&&w[d].next!=NULL&&visit(d))
	{
		q=d;return;

	}//�ҳ��µ�����
	pr[d]=1;
	p=&w[d];p=p->next;
	while(p!=NULL)
	{
		DFS(p->point,k1+1);
		p=p->next;
	}
	return ;
}
int main()
{

	int a,b;
	int i,q1;
	node *p,*px;
	scanf("%d%d%d",&n,&s,&k);
	for(i=0;i<n;i++)
	{
		w[i].point=i;
		w[i].next=NULL;
	}
	k--;//��0��ʼ����Ҫ��������λ�ü�1
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		px=(node *)malloc(sizeof(node));
		px->point=b;
		px->next=NULL;
		p=&w[a];
		while(p->next!=NULL)
			p=p->next;
		p->next=px;
		px=(node *)malloc(sizeof(node));
		px->point=a;
		px->next=NULL;
		p=&w[b];
		while(p->next!=NULL)
			p=p->next;
		p->next=px;
	}
	DFS(s,-1);//�ó��µ�����
	for(i=0;i<n;i++)
		pr[i]=po[i];
	q1=q;q=0;
	deep(q1,1);q-=k;a=q;
	for(i=0;i<n;i++)
		pr[i]=po[i];
	insert(q1,a,1);
	printf("%d\n",q);//�˴��ó�����Ҫ������λ�ã���ʹ��while������ɴ���
	return 0;
}