//7-2 二叉树最长匹配前后缀路径
#include<bits/stdc++.h>

using namespace std;
int t;

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

int main()
{
	cin>>t;
	while(t--)
	{
		node *bt=creat();
		
	}
	return 0;
}
