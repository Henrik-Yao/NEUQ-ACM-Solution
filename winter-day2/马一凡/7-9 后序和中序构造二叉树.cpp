#include<iostream>
#include<malloc.h>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int in[100100],last[100100];
int flag=0; 

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTNode* Create(int lastL, int lastR, int inL, int inR)
{
	if(flag == 1) return NULL;
	if(inL > inR || lastL > lastR)	
		return NULL; 	
	
	BiTree root = new BiTNode;		
	root->data = last[lastR];		
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == last[lastR])		
			break;
	} 
	if(k>=inR && in[k]!=last[lastR]){
		flag = 1;
		return NULL;
	}	
	
	int numLeft = k-inL;	
	

	root->lchild = Create(lastL, lastL+numLeft-1, inL, k-1);
	

	root->rchild = Create(lastL+numLeft, lastR-1, k+1, inR);
	
	return root;
}

void PreOrderTraverse(BiTree T){
	if(T == NULL)
		return;
	printf("%d ",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
	
}


int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d",&last[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&in[i]);
	}
	
		BiTree T ;
		int inL,inR,lastL,lastR;
		flag = 0;
	
	
		T = (BiTree)malloc(sizeof(BiTNode));
	
		T = Create(0, n-1, 0, n-1);
	
			PreOrderTraverse(T);
			printf("\n");
		
	
	
	

	
	return 0;
}


