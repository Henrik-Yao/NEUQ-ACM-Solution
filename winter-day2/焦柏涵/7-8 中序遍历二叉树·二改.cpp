#include <bits/stdc++.h>
using namespace std;
struct btree{
	int data;
	btree *lchild,*rchild;
};
void creat_tree(btree *t,int a[],int i,int n)
{
	if(a[i]==0)
	{
		t=NULL;return;
	}
	else
	{
		t=new btree;
		t->data=a[i];
	}
	if(2*i<=n)
	{
		creat_tree(t->lchild,a,2*i,n);
	}
	else t->lchild=NULL;
	if(2*i+1<=n)
	{
		creat_tree(t->rchild,a,2*i+1,n);
	}
	else t->rchild=NULL;
}
void search_left(btree* t)
{
	if(t==NULL) return;
	search_left(t->lchild);
	cout<<t->data<<" ";
	search_left(t->rchild);
}
void search_right(btree* t)
{
	if(t==NULL) return;
	search_right(t->lchild);
	cout<<" "<<t->data;
	search_right(t->rchild);
}
int Depth(btree *t)
{
    int l,r;
    if(t==NULL)
        return 0;
    else
    {
        l=Depth(t->lchild);
        r=Depth(t->rchild);
        if(l>r)
            return l+1;
        else
            return r+1;
    }
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		btree *t;
		int n,a[10001];
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		creat_tree(t,a,1,n);
		search_left(t->lchild);
		cout<<t->data;
		search_right(t->rchild);
		cout<<endl<<Depth(t)<<endl;
	}
	return 0;
}
