#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left,*right;
	int d;
};
struct node *root=NULL,*current,*p;
int r=0;
void btree()
{
	int data;
	scanf("%d",&data);
	while(data!=0)
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=data;
		current->left=NULL;
		current->right=NULL;
		if(root==NULL)
		{
			root=current;
			p=current;
			
		}
		else
		{
			p=root;
			while(1)
			{
				if(current->d>p->d)
				{
					if(p->right==NULL)
						break;
					p=p->right;
				}
				else
				{
					if(p->left==NULL)
						break;
					p=p->left;
				}
			}
			if(current->d>p->d)
				p->right=current;
			else
				p->left=current;
		}
		scanf("%d",&data);
	}
}
struct node *find(int y)
{
	struct node *parent;
	p=root;parent=p;
	if(parent->d==y)
	{
		r=0;
		return parent;
	}
	else
	{
	while(1)
	{
		parent=p;
		if(y>p->d)
		{
			if(p->right==NULL)
			{
				printf("sorry didn't find this number\n");
				p=root;
				return NULL;
			}
			p=p->right;
			r=-1;
		}
		if(y<p->d)
		{
			if(p->left==NULL)
			{
				printf("sorry didn't find this number\n");
				p=root;
				return NULL;
			}
			p=p->left;
			r=1;
		}
		if(y==p->d)
			return parent;
	}
	}
}
void del(struct node *parent)//paretn为删除节点的前一个节点，p为删除节点
{
	struct node *t;
	if(r==-1)
		p=parent->right;
	if(r==1)
		p=parent->left;
	if(r==0)
		p=parent;
	if(p->left==NULL&&p->right==NULL)//无左右子树
	{
	//	printf("11111111111111111\n");
		if(r==-1)
		{parent->right=NULL;free(p);}
		if(r==1)
		{parent->left=NULL;free(p);}
		return;
	}
	if(p->left!=NULL&&p->right==NULL)//有左子树，无右子树
	{
	//	printf("2222222222222222\n");
		parent->left=p->left;
		free(p);
		return;
	}
	if(p->right!=NULL&&p->left==NULL)//有右子树，无左子树
	{
	//	printf("3333333333333333333\n");
		parent->right=p->right;
		free(p);
		return;
	}
	if(p->left!=NULL&&p->right!=NULL)//左右子树均有
	{
	//	printf("444444444444444444444\n");
		t=p->left;parent=p;
		while(t->right!=NULL)
		{
			parent=t;
			t=t->right;
		}//循环结束后，t指向的值可用于替换p,parent则变成t的上一个节点
		p->d=t->d;
		if(p==parent)
			parent->left=t->left;
		else
			parent->right=t->left;
		free(t);
		return;
	}
}
void preorder(struct node *p)
{
	if(p!=NULL)
	{
		preorder(p->left);
		printf("%d ",p->d);
		preorder(p->right);
	}	
	
}
int main()
{
	int k;
	btree();
	p=root;
	preorder(p);
	printf("\n--------------------------\n");
	printf("please entry the number which you want delete\n");
	scanf("%d",&k);
	del(find(k));
	p=root;
	preorder(p);
	return 0;
}
