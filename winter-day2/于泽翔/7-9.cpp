#include <bits/stdc++.h>
using namespace std;

struct tnode{
	int data;
	int level;
	tnode* left;
	tnode* right;
};

tnode* creat_tree(int* pos, int* mid, int n)
{
    if(n==0)
    	return NULL;
    int a=pos[n-1], i=0;
    while(mid[i]!=a)
    	i++;
    
    tnode* t=new tnode;
    t->data=a;
    t->left=creat_tree(pos, mid, i);
    t->right=creat_tree(pos+i, mid+i+1, n-i-1);
    return t;
}
void putt(tnode* t)
{
	if(t==NULL)
		return;
	cout<<t->data<<' ';
	
	putt(t->left);
	putt(t->right);
}

int main(void)
{
	int n, pos[12], mid[12];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>pos[i];
	for(int i=0; i<n; i++)
		cin>>mid[i];
	
	tnode* root=new tnode;
	root=creat_tree(pos, mid, n);
	putt(root);
	
	return 0;
}