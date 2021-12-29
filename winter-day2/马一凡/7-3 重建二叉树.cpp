#include<iostream>
#include<malloc.h>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

char in[100100],last[100100];
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

int TreeDepth(BiTree T)
{
	if(T == NULL)	return 0;
	int LD = TreeDepth(T->lchild);
	int RD = TreeDepth(T->rchild);
	return (LD>RD?LD:RD)+1;
}

void PreOrderTraverse(BiTree T){
	if(T == NULL)
		return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
	
}


int main()
{
	while(~scanf("%s",last) && ~scanf("%s",in)){
		BiTree T ;
	
		int inL,inR,lastL,lastR;
		flag = 0;
	
	
		T = (BiTree)malloc(sizeof(BiTNode));
	
		int len1 = strlen(last);
		int len2 = strlen(in);
	
		T = Create(0, len1-1, 0, len2-1);
		
		if(flag==1){
			cout << "INVALID" << endl;
			continue;
		}
		else{
			printf("%d\n", TreeDepth(T));
			PreOrderTraverse(T);
			printf("\n");
		}
	
	
	}
	
	
	return 0;
}


