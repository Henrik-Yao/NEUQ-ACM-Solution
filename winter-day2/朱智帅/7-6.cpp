#include<cstdio>
#include<iostream>
#include<vector>
#define maxn 1005
using namespace std;

int in[maxn];
int pre[maxn];

struct node{
	int data;
	node* lchild;
	node* rchild; 
};

int N,M;

node* create(int preL,int preR,int inL,int inR){
	if(preL > preR){
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];//将pre的preL值放入到结构体中
	int i ;
	for(i = inL; i <= inR;i++) {
		if(in[i] == pre[preL]) break;
	}
	int numLeft = i - inL;//看左边是否还有节点 
	//注意这里没有对numLeft的数目进行判断！！ 
	root->lchild = create(preL+1,preL+numLeft,inL,i-1);
	root->rchild = create(preL+numLeft+1,preR,i+1,inR);	
	return root;
}

//inOrder
void lastOrder(node* root){
	if(root->lchild != NULL ) lastOrder(root->lchild);
	if(root->rchild != NULL ) lastOrder(root->rchild);
    cout << root->data << " ";	
}

int main(){
	cin >>  N;
	int i;
	for(i = 0;i< N;i++) cin >> pre[i];
	for(i = 0;i< N;i++) cin >> in[i];
	node* root;
	root = create(0,N-1,0,N-1);
	lastOrder(root);	
}
