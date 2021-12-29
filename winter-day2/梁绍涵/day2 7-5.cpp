#include<bits/stdc++.h>
using namespace std;
int max1=-1;
int a[20],b[20],n;
typedef struct tree
{
	struct tree *left,*right;
	int data;
}*bitree,node;
void preorder(int l1,int r1,int l2,int r2,bitree &T)
{
	if(l1>r1||l2>r2) return;
	int root;
	root=a[l1];
	
	T=new node;
	T->data=root;
	T->left=NULL;
	T->right=NULL;
	int pos;
	for(int i=l2;i<=r2;i++)
	{
		if(b[i]==root)
		pos=i;
	}
	
	preorder(l1+1,l1+pos-l2,l2,pos,T->left);
	preorder(l1+pos+1-l2,r1,pos+1,r2,T->right);
	return;
}
queue<bitree> q;
void Bfs(bitree &T)
{
	if(T==NULL) return;
	Bfs(T->left);
	Bfs(T->right);
	cout<<T->data<<" ";
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
		for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	bitree tr;
	preorder(0,n-1,0,n-1,tr);
//	cout<<111;
	Bfs(tr);
}
