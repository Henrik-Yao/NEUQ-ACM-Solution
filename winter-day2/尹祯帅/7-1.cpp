#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	int data;
	int level;
	tree *left;
	tree *right;
};
int maxlevel,sum[101],num[101];
tree* create(int level)
{
	int n;
	cin>>n;
	if(n==0) return NULL;
	tree *bt = (tree*)malloc(sizeof(tree));
	bt->data = n;
	bt->level = level;
	if(level>maxlevel) maxlevel=level;
	bt->left=create(level+1);
	bt->right=create(level+1);
	return bt;
}
void traversal(tree* bt)
{
	if(bt==NULL) return ;
	if(bt->left==NULL&&bt->right==NULL) sum[bt->level]+=bt->data,num[bt->level]++;
	traversal(bt->left);
	traversal(bt->right);
}
int main()
{
	tree* bt=create(0);
	traversal(bt);
	int maxdata=-1000,maxle=-1;
	for(int i=0;i<=maxlevel;i++)
	{
		if(sum[i]>=maxdata&&num[i]!=0) maxdata=sum[i],maxle=i;
	}
	cout<<maxle;
	return 0;
} 
