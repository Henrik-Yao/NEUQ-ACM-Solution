//7-5 ������·����
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int t;
int k,ans;
struct node
{
	int val;
	node *l,*r,*fa;
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
		bt->l=creat(bt->step);
		if(bt->l!=NULL)bt->l->fa=bt;
		bt->r=creat(bt->step);
		if(bt->r!=NULL)bt->r->fa=bt;
	}
	return bt;
}
void sum(node *a,int now,int num)
{
	if(now>k)return;
	if(num>ans)return;
	//�����׺�����ӷ�����
	if(now==k)
	{
		if()
	}
	if(a->fa!=NULL)
	{
		
	}
}
void dfs(node *bt)
{
	if(bt==NULL)return;
	dfs(bt->l);
	dfs(bt->r);
	sum(bt,0,0);
}
int main()
{
	cin>>t;
	while(t--)
	{
		node *bt=new node();
		cin>>k;
		ans=inf;
		dfs(bt);
	}
	return 0;
}
