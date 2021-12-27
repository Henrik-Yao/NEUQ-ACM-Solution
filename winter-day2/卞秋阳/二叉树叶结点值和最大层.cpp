#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int maxlevel=0;
int sum[10086];
int num[10086];
typedef struct TreeNode*PrtToNode;
typedef struct TreeNode*BinTree;
typedef struct TreeNode
{
	int data;
	int level;
	PrtToNode left;
	PrtToNode right;
}TreeNode;
BinTree createTree(int level)
{   int n;
	cin>>n;
	if(n==0) return NULL;
	BinTree BT = (BinTree)malloc(sizeof(TreeNode));
	BT->data=n;
	BT->level = level;
	if (BT->level > maxlevel)
		maxlevel = BT->level;
	BT->left = createTree(level+1);
	BT->right = createTree(level+1);
	return BT;

}
void InorderTraversal(BinTree BT)
{
	if (BT == NULL) return;
	if (BT->left == NULL && BT->right == NULL) 
	{
		sum[BT->level] += BT->data;
		num[BT->level]++;
	}
	InorderTraversal(BT->left);
	InorderTraversal(BT->right);
}
int main()
{
	BinTree BT = createTree(0);
	InorderTraversal(BT);
	int maxnum=-1000,level=-1;
	for (int i = 0; i <= maxlevel; i++) 
	{
		if (sum[i] >= maxnum && num[i]!=0)
		 {
			
			maxnum = sum[i];
			level = i;
		}
	}
	cout<<level;
	return 0;
}

