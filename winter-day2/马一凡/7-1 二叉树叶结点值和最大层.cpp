#include<iostream>
#include<malloc.h>
using namespace std;

int b[100100]={0};
int ii=1;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateTree(BiTree &T)
{
	int ch;
	scanf("%d",&ch);
	if(ch == 0)
		T = NULL;
	else
	{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateTree(T->lchild); 
		CreateTree(T->rchild);
	}
}

void P(BiTree T){
	if(T){
		if(T->lchild == NULL && T->rchild == NULL)
			b[ii]+=T->data;
			 
		P(T->lchild); 
		P(T->rchild); 
		 if(T->lchild != NULL && T->rchild != NULL) ii++;
	}
	return ;
}

int  compare(int *b, int ii){
	int i, j, temp=b[0],l=0;
	for (j = 1; j < ii; j++){
		if(temp<=b[j]){
			temp = b[j];
			l=j;
		}	 
	}
	
	return l;
}

int main(){
	BiTree T ;
	char ch;
	int t=0; 

	T = (BiTree)malloc(sizeof(BiTNode));
	CreateTree(T);
	
	if(T->lchild == NULL && T->rchild == NULL){
		cout << "0";
		return 0;
	}
    P(T);
      
	int sum = compare(b,ii);
      
    cout << sum << endl;
	
	return 0;
} 
