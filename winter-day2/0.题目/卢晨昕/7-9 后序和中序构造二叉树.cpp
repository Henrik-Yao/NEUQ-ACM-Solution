//
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
int mid[25];
int post[25];
struct node
{
	node *l,*r;
	int val;
};
node *build(int poststart,int postend,int midstart,int midend)
{
	node *root=new node();
	root->l=NULL;
	root->r=NULL;
	root->val=post[postend];
	int len=0;
	while(mid[midstart+len]!=root->val)len++;//n-1Îª×ó 
	if(len-1>=0)
		root->l=build(poststart,poststart+len-1,midstart,midstart+len-1);
	if(midstart+len<midend)
		root->r=build(poststart+len,postend-1,midstart+len+1,midend);
	return root;
}
void vis(node *a)
{
	if(a==NULL)return;
	cout<<a->val<<" ";
	vis(a->l);
	vis(a->r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>post[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>mid[i]; 
	}
	node *bt=build(1,n,1,n);
	vis(bt);
	return 0;
}
