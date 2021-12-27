//7-5 二叉树路径和
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
int pre[25],mid[25];
struct node
{
	int val;
	node *l,*r;
};
node *build(int prestart,int preend,int midstart,int midend)
{
	node *root=new node();
	root->val=pre[prestart]; 
	root->l=NULL;
	root->r=NULL;
	int n=0;
	while(root->val!=mid[midstart+n])n++;//n-1为 左子树长度 
	if(n>=1)root->l=build(prestart+1,prestart+n,midstart,midstart+n-1);
	if(midstart+n<midend)root->r=build(prestart+n+1,preend,midstart+n+1,midend);
	return root;
}
void vis(node *a)
{
	if(a==NULL)return;
	vis(a->l);
	vis(a->r);
	cout<<a->val<<" ";
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>pre[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>mid[i];
	}
	node *bt=build(1,n,1,n);
	vis(bt);
	return 0;
}
