#include <bits/stdc++.h>
using namespace std;
int a[3060], sf;

struct tnode{
	int data;
	tnode* left;
	tnode* right;
};

tnode* creat_tree(int n)
{
    if(a[n]==0)
    	return NULL;
    tnode* t=new tnode;
    t->data=a[n];
    
    t->left=creat_tree(n*2);
    t->right=creat_tree(n*2+1);
    
    return t;
}
void putt(tnode* t)
{
	if(t==NULL)
		return;
		
	putt(t->left);
	if(sf)
	cout<<' ';
	sf=1;
	cout<<t->data;
	putt(t->right);
	return;
}
int height(tnode* t)
{
	if(t==NULL)
		return 0;
	int l_h=height(t->left), r_h=height(t->right);
	return max(l_h+1, r_h+1);
}

int main(void)
{
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a, 0, 4*3060);
		for(int i=1; i<=n; i++)
			cin>>a[i];
		 
		tnode* root=new tnode;
		root=creat_tree(1);
		
		sf=0;
		putt(root);
		cout<<endl<<height(root)<<endl;
		
	}
	
	
	
	return 0;
}