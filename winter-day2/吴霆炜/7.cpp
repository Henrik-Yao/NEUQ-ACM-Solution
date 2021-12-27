#include<iostream>
#include<string>
#include<vector>
#include<queue> 

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *lchild,*rchild;
};

void createBinTree_pre_in(TreeNode *&root,int *pre,int *in,int a,int b,int c,int d)
{//由二叉树的先序序列和中序序列构建二叉树
	if(a <= b)
	{
		root = new TreeNode();		//创建根节点 
		root->data = pre[a];
		root->lchild = NULL;
		root->rchild = NULL;
		int i;
		for(i = c; i <= d; i++)		//中序序列中查找根的位置，此处为i 
		{
			if(in[i] == pre[a])
				break;
		}
		createBinTree_pre_in(root->lchild,pre,in,a+1,a+i-c,c,i-1);	//递归建左子树 
		createBinTree_pre_in(root->rchild,pre,in,a+i-c+1,b,i+1,d);	//递归建右子树 
	}
}

void levelOrder(TreeNode* root)		//利用队列实现二叉树的层次遍历 
{
	queue<TreeNode*>que;
	TreeNode* p = root;
	que.push(p);
	while(!que.empty())
	{
		p = que.front();   que.pop();
		cout<<p->data<<' ';
		if(p->lchild != NULL)
		{
			que.push(p->lchild);
		}
		if(p->rchild != NULL)
		{
			que.push(p->rchild);
		}
	} 
}
int main()				//test
{
	int n;
	TreeNode *root;
	int pre[100] = {};
	int in[100] = {};
	cin>>n;
	for(int i = 0;i < n;i++)cin>>pre[i];
	for(int i = 0;i < n;i++)cin>>in[i];
	createBinTree_pre_in(root,pre,in,0,n - 1,0,n - 1);
	levelOrder(root);
	return 0;
}
