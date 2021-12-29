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

typedef struct Qnode{
	BiTree tree;
	struct Qnode *next;
}QNode;

typedef struct link_queue{
	QNode *front;
	QNode *rear;
}LinkQueue;

LinkQueue* InitLinkQueue(void){
	LinkQueue *Q;
	QNode *p;
	p = (QNode*)malloc(sizeof(QNode));
	p->next = NULL;
	Q = (LinkQueue *)malloc(sizeof(LinkQueue));
	Q->front = Q->rear = p;
	return Q;
}

void InsertQueue(LinkQueue *Q, BiTree T){
	QNode *p;
	p = (QNode *)malloc(sizeof(QNode));
	p->tree = T;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
} 

BiTree DeleteLinkQueue(LinkQueue *Q ){
	QNode *p;
	BiTree T;
	p = Q->front->next;
	T = p->tree;
	Q->front->next = p->next;
	if(p == Q->rear) Q->rear = Q->front;
	free(p);
	printf("%d ",T->data);
	return T;
}

void Travel(BiTree T, LinkQueue *Q){
	InsertQueue(Q, T);
	while(Q->rear != Q->front){
		BiTree Tree = DeleteLinkQueue(Q );
		if(Tree->lchild != NULL)
			InsertQueue(Q, Tree->lchild);
		if(Tree->rchild != NULL)
			InsertQueue(Q, Tree->rchild);
	}
	
	return;
}


BiTNode* Create(int preL, int preR, int inL, int inR)
{

	if(preL > preR)		
		return NULL; 	
	
	BiTree root = new BiTNode;		
	root->data = pre[preL];		
	int k;
	for(k = inL; k <= inR; k++)
		if(in[k] == pre[preL])	
			break;
	
	int numLeft = k-inL;		
	
	
	root->lchild = Create(preL+1, preL+numLeft, inL, k-1);
	
	
	root->rchild = Create(preL+numLeft+1 , preR, k+1, inR);
	
	return root;	
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
		
	LinkQueue *Q;
	Q = InitLinkQueue();
	
	Travel(T,Q); 
		
	return 0;
}


