#include <iostream>
#include <queue>
using namespace std;
struct tree{
	int data;
	tree * lchild;
	tree * rchild;
};
queue<tree> lookup;
int n;
tree * createtree(int prestart,int preend,int instart,int inend,int pre[],int in[]){
	tree * BT = new tree;
	if(prestart>preend||instart>inend) return NULL;
	if(prestart==preend&&instart==inend){
		BT->lchild=NULL;
		BT->rchild=NULL;
		BT->data=pre[prestart];
		return BT;
	}
	int front=pre[prestart];int i;
	for(i=0;i<n;i++) if(in[i]==front) break;
	int partleft=i-instart;
	int partright=inend-i;
	BT->data=front;
	BT->lchild=createtree(prestart+1,prestart+partleft,instart,i-1,pre,in);
	BT->rchild=createtree(prestart+1+partleft,prestart+partleft+partright,i+1,i+partright,pre,in);
	return BT;
}
void printtree(tree *BT){
	
}
int main(){
	cin >> n;
	int pre[n],in[n];
	for(int i=0;i<n;i++) cin>>pre[i];
	for(int i=0;i<n;i++) cin>>in[i];
	tree * ROOT=new tree;
	ROOT=createtree(0,n-1,0,n-1,pre,in);
	lookup.push(*ROOT);
	while(!lookup.empty()){
		tree *TOP=&lookup.front();
		cout << TOP->data << " ";
		if(TOP->lchild!=NULL) lookup.push(*TOP->lchild); 
		if(TOP->rchild!=NULL) lookup.push(*TOP->rchild); 
		lookup.pop();
	}
	cout << endl;
	return 0;
}