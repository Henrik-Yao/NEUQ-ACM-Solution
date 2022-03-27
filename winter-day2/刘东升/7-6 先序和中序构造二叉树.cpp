#include<bits/stdc++.h>
using namespace std;
int pre[15],mid[15],last[15];int num=0;
struct Node
{
	int date;
	Node* left;
	Node* right;
};
Node* rebuild(int pre[],int mid[],int len);
void show(Node* t);
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
		cout<<last[i]<<" ";
}
Node* rebuild(int pre[],int mid[],int n)
{
	if(n==0)//¿ÕµÄÊ±ºò 
	return NULL;
	Node* x=new Node;
	x->date=pre[0];
	int i;
	for(i=0;i<n;i++)
	if(mid[i]==pre[0])
	break;
	x->left=rebuild(pre+1,mid,i);
	x->right=rebuild(pre+i+1,mid+i+1,n-i-1);
	return x;
}
void show(Node* t)
{
	if(t==NULL)
	return ;
	show(t->left);
	show(t->right);
	last[++num]=t->date;
}
