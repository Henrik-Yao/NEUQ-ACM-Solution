#include<bits/stdc++.h>
using namespace std;
int sum[110], num[110], maxl=0;

struct tree{
	int data;
	int level;
	tree* left;
	tree* right;
};
tree* newtree(int le)
{
	int n;
	cin>>n;
	if(n==0)
		return NULL;
	
	tree* T=new tree;
	T->data=n;
	T->level=le;
	
	if(T->level>maxl)
		maxl=T->level;
	T->left=newtree(le+1);
	T->right=newtree(le+1);
	
	return T;
}
void itv(tree* T)
{
	if(T==NULL)
		return;
	if(T->left==NULL&&T->right==NULL)
	{
		sum[T->level]+=T->data;
		num[T->level]++;
	}
	itv(T->left);
	itv(T->right);
}
int main()
{
	tree* a=newtree(0);
	itv(a);
	int maxx=-999, lev=-1;
	
	for(int i=0; i<=maxl; i++)
		if(sum[i]>=maxx&&num[i]!=0)
		{
			maxx=sum[i];
			lev=i;
		}	
	
	cout<<lev;
	
	return 0;
}