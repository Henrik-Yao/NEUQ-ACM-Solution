#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct TreeNode
{
	int data;
    int num;
	TreeNode *left,*right;	
};
int t;
void createTree(TreeNode *&t,int *a,int num,int n);
void inorder1(TreeNode *t);
void inorder2(TreeNode *t);
int getdeep(TreeNode *t);
int main()
{
	cin>>t;
	while(t--)
	{
		TreeNode *root;
		int n;
		int a[10000];
		cin>>n;
		for(int i=1;i<=n;i++)
		{
            cin>>a[i];
        }
		createTree(root,a,1,n);
		inorder1(root->left);
        cout<<root->data;
        inorder2(root->right);
		cout<<endl;
		cout<<getdeep(root)<<endl;
	}
	return 0;
}
void createTree(TreeNode *&t,int *a,int num,int n)
{
	if(a[num] == 0)
	{
		t=NULL;
		return;
	}
	else
    {
		t=new TreeNode;
		t->data = a[num];
	}
	if(num*2 <= n)
	{
		createTree(t->left,a,num*2,n);
	}
	else t->left=NULL;
	if(num*2+1 <= n)
	{
		createTree(t->right,a,num*2+1,n);
	}
	else t->right=NULL;
}
void inorder1(TreeNode *t)
{
	if(t==NULL)
	return;
	inorder1(t->left);
	cout<<t->data<<" ";
	inorder1(t->right);
}
void inorder2(TreeNode *t)
{
	if(t==NULL)
	return;
	inorder2(t->left);
	cout<<" "<<t->data;
	inorder2(t->right);
}
int getdeep(TreeNode *t)
{
	int l,r;
	if(t==NULL)
		return 0;
	else{
		l=getdeep(t->left);
		r=getdeep(t->right);
		if(l>r)
		return l+1;
		else return r+1;
	}
}
