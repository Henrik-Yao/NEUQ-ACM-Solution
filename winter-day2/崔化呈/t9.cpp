#include<bits/stdc++.h>
using namespace std;
int in[11],post[11];
struct tree
{
	int da;
	tree* l;
	tree* r;
};
tree* create(int inn,int posn,int n)
{
	if(n<=0){return NULL;}
	tree* bt=new tree;
	int root=post[n-1+posn];
	bt->da=root;
	int i;	
	for(i=inn;i<inn+n;i++)
	{
		if(in[i]==root){break;}
	}
	int k=i-inn;
	bt->l=create(inn,posn,k);
	bt->r=create(i+1,posn+k,n-k-1);
	return bt;
}
void show(tree* bt)
{
	if(bt!=NULL)
	{
	cout<<bt->da<<" ";
	show(bt->l);
	show(bt->r);
	}
	
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){cin>>post[i];}
	for(int i=0;i<n;i++){cin>>in[i];}
	tree* bt=create(0,0,n);
	show(bt);
}
