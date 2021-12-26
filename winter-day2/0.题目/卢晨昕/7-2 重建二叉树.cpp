//根据后根序列和中根序列 得到前根序列 
#include<bits/stdc++.h>

using namespace std;
int maxn=0;
bool ans;
string in,post;
struct node
{
	char val;
	int step;
	node *l,*r;
};
node *creat(int poststart,int postend,int instart,int inend)
{
	node *root=new node();
	root->val=post[postend];
	root->l=NULL;
	root->r=NULL;
	int n=0;
	bool flag=0;
	for(n;n<=inend;n++)//左子树长度为n-1,n为根节点 
	{
		if(in[instart+n]==root->val)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		if(n>=1)
			root->l=creat(poststart,poststart+n-1,instart,instart+n-1);
	
		if(instart+n<inend)
			root->r=creat(poststart+n,postend-1,instart+n+1,inend);
	}
	
		
	if(!flag)ans=false;
	
	return root;
}
void high(node *x,int s)
{
	if(x==NULL)return;
	x->step=s;
	if(s>maxn)maxn=s;
	high(x->l,s+1);
	high(x->r,s+1);
}
void visit(node *x,int s)
{
	if(x==NULL)return;
	if(s!=-1)cout<<x->val;
	visit(x->l,s+1);
	visit(x->r,s+1);
}
int main()
{
	while(cin>>post)
	{
		cin>>in;
		
		maxn=0;ans=true;
		
		node *x=creat(0,post.length(),0,in.length());
		if(ans)
		{
			high(x,-1);//-1层为初始的空节点 
			cout<<maxn<<endl;
			visit(x,-1);
			cout<<endl;
		}
		else
		{
			cout<<"INVALID"<<endl;
		}
	}
	return 0;
}
