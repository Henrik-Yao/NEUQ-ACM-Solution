#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode *BiTree;
struct TreeNode{
	int num;
	int level;
	TreeNode *left;
	TreeNode *right;
};
int sum[100];
int num[100];
int maxlevel=0;
BiTree create(int level)
{
	int num;
	cin>>num;
	if(num==0)
	{
		return NULL;
	} 	
	BiTree bitree=(BiTree)malloc(sizeof(TreeNode));
	bitree->num=num;
	bitree->level=level;
	if(bitree->level>maxlevel)
	{
		maxlevel=bitree->level;
	}	
	bitree->left=create(level+1);
	bitree->right=create(level+1);
	return bitree;
}
void Compair(BiTree bitree)
{
	if(bitree==NULL)
	{
		return;
	}	
	if(bitree->left==NULL&&bitree->right==NULL)
	{
		sum[bitree->level]+=bitree->num;
		num[bitree->level]++;
	}
	Compair(bitree->left);
	Compair(bitree->right);
}
int main()
{
	BiTree bitree=create(0);
	Compair(bitree);
	int max=-1000,level=-1;
	for(int i=0;i<=maxlevel;i++)
	{
		if (sum[i]>=max&&num[i]!=0)
		{
			max=sum[i];
			level=i;
		}
	}
	cout<<level<<endl;
	return 0;
}
