#include<iostream>
#include<malloc.h>
#include<cmath>
using namespace std;

int ch[100100]={0};
int n;
int book=0;

typedef struct BiTNode{
	int data;
	int num;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void CreateTree(BiTree &T, int num){
	
	T = (BiTNode*)malloc(sizeof(BiTNode));
	if(num>n){
		T = NULL;
		return;
	} 
	if(ch[num] == 0){
		T = NULL;
		return;
	}
	T->data = ch[num];
	CreateTree(T->lchild,num*2); 
	CreateTree(T->rchild,num*2+1);
	return;
}

void InOrderTraverse(BiTree T){
	if(T == NULL)
		return;
	InOrderTraverse(T->lchild);
	if(book==1) cout << " ";
	printf("%d",T->data);
	book = 1;
	InOrderTraverse(T->rchild);
}


int main(){
	int T;
	cin >> T;
	while(T--){
		int nn=0;
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> ch[i];
			if(ch[i]!=0) nn=i;
		}
		BiTree T ;

		T = (BiTree)malloc(sizeof(BiTNode));
		CreateTree(T,1);
		book = 0;
		InOrderTraverse(T);
		cout << endl;
		int a = log(nn)/log(2)+1;
		cout << a << endl;
	}
	

	
	
	return 0;
	
}
