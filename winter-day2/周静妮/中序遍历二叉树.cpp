#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node_Tree
{
	int data,num;
	Node_Tree *le,*ri;	
};
int t;
void createTree(Node_Tree *&t,int *a,int num,int n)
{
	if(a[num]==0)
	{
		t=NULL;
		return;
	}
	else{
		t=new Node_Tree;
		t->data=a[num];
		}
	if(num*2<=n)
	{
		createTree(t->le,a,num*2,n);
	}
	else t->le=NULL;
	if(num*2+1<=n)
	{
		createTree(t->ri,a,num*2+1,n);
	}
	else t->ri=NULL;
}
void inorder1(Node_Tree *t)
{
	if(t==NULL)
	return;
	inorder1(t->le);
	cout<<t->data<<" ";
	inorder1(t->ri);
}
void inorder2(Node_Tree *t)
{
	if(t==NULL)
	return;
	inorder2(t->le);
	cout<<" "<<t->data;
	inorder2(t->ri);
}
int getdeep(Node_Tree *t)
{
	int l,r;
	if(t==NULL)
		return 0;
	else{
		l=getdeep(t->le);
		r=getdeep(t->ri);
		if(l>r)
		return l+1;
		else return r+1;
	}
}
int main()
{
	cin>>t;
	while(t--)
	{
		Node_Tree *T;
		int n;
		int a[10000];
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		createTree(T,a,1,n);
		inorder1(T->le);cout<<T->data;inorder2(T->ri);
		cout<<endl;
		cout<<getdeep(T)<<endl;
	}
	return 0;
}
