#include<bits/stdc++.h>
using namespace std;
int mid[15],post[15];
struct Node
{
	int date;
	Node *left;
	Node *right;
};
Node* rebuild(int post[],int mid[],int len)
{
	if(len==0)
	return NULL;
	Node *t=new Node;
	t->date=post[len-1];
	int i=0;
	for(;i<len;i++)
	if(post[len-1]==mid[i])
	break;
	if(i==len)
	return NULL;
	else
	{
		t->left=rebuild(post,mid,i);
		t->right=rebuild(post+i,mid+i+1,len-i-1);
	}
	return t;
}
void show(Node* t)
{
	if(t==NULL)
	return ;
	cout<<t->date<<" ";
	show(t->left);
	show(t->right);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>post[i];
	for(int i=0;i<n;i++)
	cin>>mid[i];
	Node *T=new Node;
	T=rebuild(post,mid,n);
	show(T);
}
