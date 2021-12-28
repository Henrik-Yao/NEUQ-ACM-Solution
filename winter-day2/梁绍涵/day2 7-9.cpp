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
	root=a[r1];
	
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
	int k=pos-l1;
	preorder(l1,pos-1,l2,l2+k-1,T->left);
	preorder(pos+1,r1,l2+k,r2-1,T->right);
	return;
}
queue<bitree> q;
void Bfs(bitree &T)
{
	if(T==NULL) return;
	cout<<T->data<<" ";
	Bfs(T->left);
	Bfs(T->right);
	
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
