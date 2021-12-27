//7-7 °´²ã±éÀú¶ş²æÊ÷
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
int pre[25];
int mid[25];
struct node
{
	node *l,*r;
	int val;
};
node *build(int prestart,int preend,int midstart,int midend)
{
	node *root=new node();
	root->l=NULL;
	root->r=NULL;
	root->val=pre[prestart];
	int len=0;
	while(mid[midstart+len]!=root->val)len++;
	if(len>=1)
		root->l=build(prestart+1,prestart+len,midstart,midstart+len-1);
	if(midstart+len<midend)
		root->r=build(prestart+len+1,preend,midstart+len+1,midend);
	return root;
}
void vis(node *a)
{
	queue<node*>q;
	q.push(a);
	while(!q.empty())
	{
		node *a=q.front();
		q.pop();
		cout<<a->val<<" ";
		node *x=a->l;
		node *y=a->r;
		if(x!=NULL)q.push(x);
		if(y!=NULL)q.push(y);
	}
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
