#include<iostream>
using namespace std;

int mid[100];
int aft[100];

struct node{
	int data;
	node *left;
	node *righ;
	node(void)
	{
		left=NULL;
		righ=NULL;
	}
	~node(void)
	{
		if(left!=NULL)	delete left;
		if(righ!=NULL)	delete righ;
	}
};

node* creat(int f_m, int l_m, int f_a, int l_a)
{
	if(f_m>l_m)	return NULL;
	if(f_a>l_a)	return NULL;
	if(f_m==l_m)
	{
		node *root=new node;
		root->data=mid[f_m];
		return root;
	}
	if(f_a==l_a)
	{
		node *root=new node;
		root->data=aft[f_a];
		return root;
	}
	
	node *root=new node;
	int ro;
	for(ro=f_m; ro<=l_m; ro++)
	if(mid[ro]==aft[l_a])	break;
	root->data=mid[ro];
	
	int lon_left=ro-f_m;
	int lon_righ=l_m-ro;
	
	root->left=creat(f_m, ro-1, f_a, f_a+lon_left-1);
	root->righ=creat(ro+1, l_m, l_a-lon_righ, l_a-1);
	return root;
}

void pre(node *root)
{
	cout<<root->data<<" ";
	if(root->left!=NULL)	pre(root->left);
	if(root->righ!=NULL)	pre(root->righ);
	return;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++)	cin>>aft[i];
	for(int i=0; i<n; i++)	cin>>mid[i];
	if(n)
	{
		node *root=creat(0, n-1, 0, n-1);
		pre(root);
		delete root;
	}
	return 0;
}
