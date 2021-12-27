#include <bits/stdc++.h>
 using namespace std;

int b[100]={0};
typedef struct BitreeNode
{
	int date;
	struct BitreeNode *lchild,*rchild;
}*LinktreeNode;

LinktreeNode createbitree1()
{
	int date;
	LinktreeNode node;
	scanf("%d",&date);
	if(date==0)	node=NULL;
	else
	{
		node=(LinktreeNode)malloc(sizeof(BitreeNode));
		node->date=date;
		node->lchild= createbitree1();
		node->rchild= createbitree1();
	}
	return node;
}

int sum=0,m=1;

void P(LinktreeNode x)
{
	if(x)
	{
		if(x->lchild==NULL && x->rchild==NULL)
			b[m]+=x->date;
		P(x->lchild);
		P(x->rchild);
		if(x->lchild!=NULL && x->rchild!=NULL) m++;
	}
	return;
}

int compare(int *a,int k)
{
	int i,j,temp=a[0],l=0;
	for(j=1;j<k;j++)
	{
		if(temp<=a[j])
		{
			temp=a[j];
			l=j;
		 } 
	}
	return l;
}
int main()
{
	LinktreeNode T=NULL;
	T=createbitree1();
	if(T->lchild==NULL && T->rchild==NULL)
	{
		cout<<"0";
		return 0;
	}
	P(T);
	int l=compare(b,m);
	cout<<l<<endl;
	return 0;
}
