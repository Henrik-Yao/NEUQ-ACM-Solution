#include<bits/stdc++.h>
using namespace std;
int pre[15],mid[15],ans[15];
int num=0;
struct Node
{
	int date;
	Node* left;
	Node* right;
};
Node* rebuild(int pre[],int mid[],int len)
{
	if(len==0)
	return NULL;
	Node* x=new Node;
	x->date=pre[0];
	int i;
	for(i=0;i<len;i++)
	if(mid[i]==pre[0])
	break;
	x->left=rebuild(pre+1,mid,i);
	x->right=rebuild(pre+i+1,mid+i+1,len-i-1);
	return x;
}
void show(Node* t)
{
	if(t==NULL)
	return ;
	show(t->left);
	show(t->right);
	ans[++num]=t->date;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>pre[i];
	for(int i=0;i<n;i++)
	cin>>mid[i];
	Node* t=new Node;
	t=rebuild(pre,mid,n);
	show(t);
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";
}
