#include<iostream>
using namespace std;

#define ll long long

struct TreeNode
{
	int data;
	TreeNode *le,*ri;	
};
int n;
int rear[10000];
int mid[10000];
void InitTree(TreeNode *&t,int *rear,int *mid,int n)
{
	int num;
	int *p;
	if(n<=0)
	{
		t=NULL;
		return;
	}
	t=new TreeNode;
	p=mid;
	while(*p!=rear[n-1])
	{
		p++;
	}
	t->data=*p;
	num=p-mid;
	InitTree(t->le,rear,mid,num);
	InitTree(t->ri,rear+num,mid+num+1,n-num-1);
}
void preorder(TreeNode *t)
{
	if(t==NULL)
	{
        return;
    }

	cout<<t->data<<" ";
	preorder(t->le);
	preorder(t->ri);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
        cin>>rear[i];
    }
	for(int i=0;i<n;i++)
	{
        cin>>mid[i];
    }

	TreeNode *root;
	InitTree(root,rear,mid,n);
	preorder(root);

	return 0;
}