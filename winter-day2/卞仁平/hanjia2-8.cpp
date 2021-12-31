#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct tree
{
	int data,num;
	tree *l,*r;	
};
int t;
void create(tree *&t,int *a,int num,int n)
{
	if(a[num]==0)
	{
		t=NULL;
		return;
	}
	else
    {
		t=new tree;
		t->data=a[num];
	}
	if(num*2<=n)
	{
		create(t->l,a,num*2,n);
	}
	else t->l=NULL;
	if(num*2+1<=n)
	{
		create(t->r,a,num*2+1,n);
	}
	else t->r=NULL;
}
void inorder1(tree *t)
{
	if(t==NULL)
	return;
	inorder1(t->l);
	cout<<t->data<<" ";
	inorder1(t->r);
}
void inorder2(tree *t)
{
	if(t==NULL)
	return;
	inorder2(t->l);
	cout<<" "<<t->data;
	inorder2(t->r);
}
int getdeep(tree *t)
{
	int l,r;
	if(t==NULL)
		return 0;
	else
    {
		l=getdeep(t->l);
		r=getdeep(t->r);
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
		tree *T;
		int n;
		int a[10000];
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		create(T,a,1,n);
		inorder1(T->l);cout<<T->data;inorder2(T->r);
		cout<<endl;
		cout<<getdeep(T)<<endl;
	}
	return 0;
}