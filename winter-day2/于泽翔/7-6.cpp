#include <bits/stdc++.h>
using namespace std;

struct tnode{
	int data;
	int level;
	tnode* left;
	tnode* right;
};

tnode* creat_tree(int* pre, int* mid, int n)
{
    if(n==0)
    	return NULL;
    int a=pre[0], i=0;
    while(mid[i]!=a)
    	i++;
    
    tnode* t=new tnode;
    t->data=a;
    t->left=creat_tree(pre+1, mid, i);
    t->right=creat_tree(pre+i+1, mid+i+1, n-i-1);
    
    return t;
}
void putt(tnode* t)
{
	if(t==NULL)
		return;
	putt(t->left);
	putt(t->right);
	
	cout<<t->data<<' ';
}

int main(void)
{
	int n, pre[12], mid[12];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>pre[i];
	for(int i=0; i<n; i++)
		cin>>mid[i];
	
	tnode* root=new tnode;
	root=creat_tree(pre, mid, n);
	putt(root);
	
	return 0;
}