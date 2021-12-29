#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<queue>
using namespace std;
 
 
typedef struct node
{
	int data;
	struct node * leftChild;
	struct node * rightChild;
}BTNode;
 
BTNode *createBT(int *pre , int *in ,int n)
{
	BTNode *b;
	int *p ;
	int k ;
	if(n<=0)
		return NULL;
	b=(BTNode *)malloc(sizeof(BTNode));
	b->data = *pre ;
	int j=0;
	for(p=in;p<in+n;p++)
	{
		if(*p == *pre)
			break;
	}
	k=p-in;
	b->leftChild = createBT(pre+1,in,k);
	b->rightChild = createBT(pre+1+k,p+1,n-k-1);
	return b ;
}
 
void showBTPreOrder(BTNode *b)
{
	if(b != NULL)
	{
		cout<<b->data;
		showBTPreOrder(b->leftChild);
		showBTPreOrder(b->rightChild);
 
	}
}
 
//中序遍历二叉树BinaryTree:先遍历左子树，接着遍历根节点，左后遍历右子树
//(不是左孩子节点和右孩子节点，概念要分清哦(虽然节点也是一个树))
void showBTInOrder(BTNode *b)
{
	if(b!=NULL)
	{
		//遍历左子树
		showBTInOrder(b->leftChild);
		//遍历根节点
		printf("%c",b->data);
		//遍历右子树
		showBTInOrder(b->rightChild);
	}
}

void OrderTraverse(BTNode *t)
 {
    if (t == NULL)    
    {
        return ;
    }
    OrderTraverse(t->leftChild);
    OrderTraverse(t->rightChild);
    cout<<t->data<<" ";
 }
 
int main()
{
	BTNode *b = NULL ;
	int pre[1000];
	int mid[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>mid[i];
	}
	b=createBT(pre,mid,n);
	OrderTraverse(b);

	return 0 ;
}