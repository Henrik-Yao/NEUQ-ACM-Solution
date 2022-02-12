#include<bits/stdc++.h>
using namespace std;
int mid[15],post[15];
struct Node
{
	int date;
	Node *left;
	Node *right;
};
Node* rebuild(int post[],int mid[],int last);
void show(Node* t);
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
Node* rebuild(int post[],int mid[],int last)
{
	if(last==0)
	return NULL;
	Node *t=new Node;
	t->date=post[last-1];
	int i=0;
	for(;i<last;i++)
	if(post[last-1]==mid[i])
	break;
	if(i==last)
	return NULL;
	else
	{
		t->left=rebuild(post,mid,i);
		t->right=rebuild(post+i,mid+i+1,last-i-1);
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
