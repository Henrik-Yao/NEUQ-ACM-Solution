#include<iostream>
using namespace std;

int mid[100];
int pre[100];

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

node* flor[10][10];

node* creat(int f_m, int l_m, int f_p, int l_p)
{
	if(f_m>l_m)	return NULL;
	if(f_p>l_p)	return NULL;
	if(f_m==l_m)
	{
		node *root=new node;
		root->data=mid[f_m];
		return root;
	}
	if(f_p==l_p)
	{
		node *root=new node;
		root->data=pre[f_p];
		return root;
	}
	
	node *root=new node;
	int ro;
	for(ro=f_m; ro<=l_m; ro++)
	if(mid[ro]==pre[f_p])	break;
	root->data=mid[ro];
	
	int lon_left=ro-f_m;
	int lon_righ=l_m-ro;
	
	root->left=creat(f_m, ro-1, f_p+1, f_p+lon_left);
	root->righ=creat(ro+1, l_m, l_p-lon_righ+1, l_p);
	return root;
}

void cla(node *root, int flo)
{
	int are;
	for(are=0; flor[flo][are]!=0; are++);
	flor[flo][are]=root;
	if(root->left!=NULL)	cla(root->left, flo+1);
	if(root->righ!=NULL)	cla(root->righ, flo+1);
	return;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++)	cin>>pre[i];
	for(int i=0; i<n; i++)	cin>>mid[i];
	if(n)
	{
		node *root=creat(0, n-1, 0, n-1);
		cla(root,0);
		for(int i=0; flor[i][0]!=NULL; i++)
		for(int j=0; flor[i][j]!=NULL; j++)
			cout<<flor[i][j]->data<<" ";
		delete root;
	}
	return 0;
}
