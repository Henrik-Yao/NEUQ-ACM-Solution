//带空指针信息的二叉树先根序列
#include<bits/stdc++.h>

using namespace std;
int ans[105];
int maxn;
int maxans=-100000;
int anss;
struct node
{
	int val;
	int step;
	node *l,*r;
};
node *creat(int s)
{
	node *bt;
	int x;
	cin>>x;
	if(x==0)bt=NULL;
	else
	{
		bt=new node();
		bt->val=x;
		bt->step=s+1;
		if(bt->step>maxn)maxn=bt->step;
		bt->l=creat(bt->step);
		bt->r=creat(bt->step);
	}
	return bt;
}
void vis(node *bt)
{
	if(bt==NULL)return;
	else
	{
		if(bt->l==NULL&&bt->r==NULL)ans[bt->step]+=bt->val;//叶节点 
		vis(bt->l);
		vis(bt->r);
	}
}
int main()
{
	node *bt=creat(-1);
	vis(bt);
	for(int i=maxn;i>=0;i--)
	{
		if(ans[i]>maxans&&ans[i]!=0)//无叶节点的层不算 
		{
			maxans=ans[i];
			anss=i;
		}
	}
	cout<<anss;
	return 0;
}
