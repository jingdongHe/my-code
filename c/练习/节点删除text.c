#include<stdio.h>
#include<stdlib.h>//LEN�����ò����һ����Ǵ��������ܣ���δ����ڵ㣬��LEN��ȷ���ڵ��С���ܻ����
struct Student
{
	int num;
	float score;
	struct Student *next;
};

struct Student *creat()
{
	int n=0;
	struct Student *head=NULL;
	struct Student *p1,*p2;
	p1=(struct Student *)malloc(sizeof(struct Student));//�˴��ҽ���p1=p2....��p2ɾ��,��p1�����½ڵ㣬p2Ϊ��
	printf("please entry studrent's number and score:(entry end when number=0 and score=0)\n");
	scanf("%d %f",&p1->num,&p1->score);
	p1->next=NULL;//�����������ǽ�ÿ��ѧ������������
	while(p1->num!=0)
	{
		//n=n+1;���˴���nû�б�Ҫ,��ɾ����д����Ҫ�������ٱ������������ң�
		if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;		
		p1=(struct Student *)malloc(sizeof(struct Student));
		printf("please entry studrent's number and score:(entry end when number=0)\n");
		scanf("%d %f",&p1->num,&p1->score);
		p1->next=NULL;//�˴���p1->nextָ��null�ô��ǿ���ʱֹͣ����Ľ���
	}
	//p2->next=NULL;
	return head;
}
void print(struct Student *head1)
{
	struct Student *p;
	p=head1;//�˴���ȫû�б�Ҫ�ٽ���һ����ָ��
	/*printf("\nNow,These %d records are :\n",n);
	if(head1!=NULL)
		do
		{
			printf("%d %5.1f\n",p->num,p->score);
			p=p->next;
		}
		while(p!=NULL);*/
	while(p!=NULL)
	{
		printf("%d %5.1f\n",p->num,p->score);
		p=p->next;
	}
}
struct Student *delet(struct Student *head2)//�˴�ɾ���ڵ㣬ʹ�������仯�����п���ɾ��ͷ��㣬�ʣ��践��һ������ͷ��㣩���˴��Ҹı�������
{
	struct Student *p1,*head;
	int j;
	head=head2;//headΪ������ͷָ��
	printf("please input the student's num you want to delete:\n");
	scanf("%d",&j);
	/*p1=head2;
	if(head2!=NULL) 
		while (p1->num!=j)
		{
			p2=p1;
			p1=p1->next;
		}
		if(p1==NULL)
		{
			if(p1=head2)
				head2=p1->next;
			else
				p2->next=p1->next;
		}
		print(head2);*/
	if(head2->num==j)//ɾ��ͷ���
	{
		p1=head2;
		head=head2->next;
		free(p1);
		return head;
	}
	while(head2->next->num!=j)//�ҵ�Ҫɾ���Ľڵ����һ���ڵ�,ѭ��������head2��ָ��Ҫɾ���ڵ����һ���ڵ�
		head2=head2->next;
	p1=head2->next;//��p1���Ҫɾ���Ľڵ�
	head2->next=head2->next->next;//��Ҫɾ���Ľڵ����һ���ڵ㣬����һ��ָ�룬ָ��Ҫɾ���ڵ����һ���ڵ㣬���������ɾ���ڵ������
	free(p1);
	print(head);
	return head;
}
void main()
{
	delet(creat());
}