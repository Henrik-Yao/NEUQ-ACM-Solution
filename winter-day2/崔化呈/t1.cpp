#include<bits/stdc++.h>
using namespace std;
int maxce=0,sum[105],num[105];
struct tree
{
	int da;
	int ce;
	tree* l;
	tree* r;
}trees;
tree* create(int ceng)
{
	int n;
	cin>>n;
	if(n==0){return NULL;}
	tree* bt=(tree*)malloc(sizeof(trees));
	bt->da=n;
	bt->ce=ceng;
	if(bt->ce>maxce)
	{
		maxce=bt->ce;
	}
	bt->l=create(ceng+1);
	bt->r=create(ceng+1);
	return bt;
}
void inorder(tree* bt)
{
	if(bt==NULL){return;}
	if(bt->l==NULL&&bt->r==NULL)
	{
		sum[bt->ce]+=bt->da;
		num[bt->ce]++;
	}
	inorder(bt->l);
	inorder(bt->r);
}
int main()
{
	tree* bt=create(0);
	inorder(bt);
	int maxx=-100,ce=-1;
	for(int i=0;i<=maxce;i++)
	{
		if(num[i]!=0&&sum[i]>=maxx)
		{
			maxx=sum[i];
			ce=i;
		}
		
	}
	cout<<ce;
	return 0;
}
