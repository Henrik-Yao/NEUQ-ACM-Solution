//���ݺ�����к��и����� �õ�ǰ������ 
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
	for(n;n<=inend;n++)//����������Ϊn-1,nΪ���ڵ� 
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
			high(x,-1);//-1��Ϊ��ʼ�Ŀսڵ� 
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
