#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node_Tree
{   int data;
	Node_Tree *le,*ri;	
};
int front[1000],middle[1000];
void createTree(Node_Tree *&t,int l1,int r1,int l2,int r2);
void backorder(Node_Tree *t)
{
	if(t==NULL)return;
	backorder(t->le);
	backorder(t->ri);
	cout<<t->data<<" ";
}
int n;
int main()
{
	Node_Tree *T;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>front[i];
	}
	for(int i=1;i<=n;i++)
		{cin>>middle[i];}
	createTree(T,1,n,1,n);
	backorder(T);
	return 0;
}
void createTree(Node_Tree *&t,int l1,int r1,int l2,int r2)
{
	int i;
	t=new Node_Tree;
	if(l1>r1)
	{
		t=NULL;
		return;
	}
	t->data=front[l1];
	for(i=l2;i<=r2;i++)
	{
		if(middle[i]==front[l1])
			break;
	}
	createTree(t->le,l1+1,l1+i-l2,l2,i-1);
	createTree(t->ri,l1+i-l2+1,r1,i+1,r2);
}
