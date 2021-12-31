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

	if(preL > preR)		//�������г���С�ڵ���0ʱ��ֱ�ӷ���
		return NULL; 	
	
	BiTree root = new BiTNode;		//�½�һ���µĽ�㣬������ŵ�ǰ�������ĸ����
	root->data = pre[preL];		//�½���������Ϊ������ֵ
	int k;
	for(k = inL; k <= inR; k++)
		if(in[k] == pre[preL])		//�������������ҵ�in[k]==pre[L]�Ľ��
			break;
	
	int numLeft = k-inL;		//�������Ľ�����
	
	//����������������Ϊ[preL+1,preL+numLeft], ��������Ϊ[inL,k-1]
	//�����������ĸ�����ַ����ֵ��root����ָ��
	root->lchild = Create(preL+1, preL+numLeft, inL, k-1);
	
	//����������������Ϊ[preL+numLeft+1,preR], ��������Ϊ[k+1,inR]
	//�����������ĸ�����ַ����ֵ��root����ָ��
	root->rchild = Create(preL+numLeft+1 , preR, k+1, inR);
	
	return root;	//���ظ�����ַ
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


