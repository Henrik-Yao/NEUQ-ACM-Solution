#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Tree_Node
{
	int data;
	int level;
	Tree_Node *le;
	Tree_Node *ri;
};
int sum[105],num[105],maxlevel,maxnum=-10000000;
//按照先序遍历创建二叉树 
void createTree(Tree_Node *&t,int l)
{
	int a;
	cin>>a;
	if(a==0)
	{
		t=NULL;
		return;
	}
	else 
	{
		t=new Tree_Node;//为t开辟空间 
		t->data=a;t->level=l;
		maxlevel=max(maxlevel,l);
		createTree(t->le,l+1);
		createTree(t->ri,l+1);
	}
}
void getsum(Tree_Node *t)
{
	if(t==NULL)
		return;
	if(t->le==NULL && t->ri==NULL)
	{
		sum[t->level]+=t->data;
		num[t->level]++;
	}
	getsum(t->le);
	getsum(t->ri);
}
int main()
{
	Tree_Node *T;
	createTree(T,0);
	getsum(T);
	int level=-1;
	for(int i=0;i<=maxlevel;i++)
	{
		if(sum[i]>=maxnum && num[i]!=0)
		{
			maxnum=sum[i];
			level=i;
		}
	}
	cout<<level;
	return 0;
}
