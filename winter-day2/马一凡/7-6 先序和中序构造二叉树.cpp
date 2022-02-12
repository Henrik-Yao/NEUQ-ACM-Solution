#include<iostream>
#include<malloc.h>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int in[100100],pre[100100];


typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTNode* Create(int preL, int preR, int inL, int inR)
{

	if(preL > preR)		//先序序列长度小于等于0时，直接返回
		return NULL; 	
	
	BiTree root = new BiTNode;		//新建一个新的结点，用来存放当前二叉树的根结点
	root->data = pre[preL];		//新结点的数据域为根结点的值
	int k;
	for(k = inL; k <= inR; k++)
		if(in[k] == pre[preL])		//在中序序列中找到in[k]==pre[L]的结点
			break;
	
	int numLeft = k-inL;		//左子树的结点个数
	
	//左子树的先序区间为[preL+1,preL+numLeft], 中序区间为[inL,k-1]
	//返回左子树的根结点地址，赋值给root的左指针
	root->lchild = Create(preL+1, preL+numLeft, inL, k-1);
	
	//右子树的先序区间为[preL+numLeft+1,preR], 中序区间为[k+1,inR]
	//返回右子树的根结点地址，赋值给root的右指针
	root->rchild = Create(preL+numLeft+1 , preR, k+1, inR);
	
	return root;	//返回根结点地址
}

void LastOrderTraverse(BiTree T){
	if(T == NULL)
		return;
	LastOrderTraverse(T->lchild);
	LastOrderTraverse(T->rchild);
	printf("%d ",T->data);
}


int main()
{
		int n;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> pre[i];
		}
		for(int i=0; i<n; i++){
			cin >> in[i];
		}
		BiTree T ;
	
		int inL,inR,lastL,lastR;
		
		T = (BiTree)malloc(sizeof(BiTNode));
		T = Create(0, n-1, 0, n-1);
		
			LastOrderTraverse(T);
			printf("\n");

	return 0;
}


