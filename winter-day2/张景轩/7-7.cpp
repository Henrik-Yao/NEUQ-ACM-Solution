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

void FloorPrint_QUEUE(BTNode *Tree) //层序遍历_队列实现
{
    queue <BTNode*> q;
    if (Tree != NULL)
    {
        q.push(Tree);   //根节点进队列
    }

    while (q.empty() == false)  //队列不为空判断
    {
        cout << q.front()->data << " "; 

        if (q.front()->leftChild != NULL)   //如果有左孩子，leftChild入队列
        {
            q.push(q.front()->leftChild);   
        }

        if (q.front()->rightChild != NULL)   //如果有右孩子，rightChild入队列
        {
            q.push(q.front()->rightChild);
        }
        q.pop();  //已经遍历过的节点出队列
    }
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
	FloorPrint_QUEUE(b);

	return 0 ;
}