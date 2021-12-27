#include <iostream>
#include <vector>
using namespace std;
vector<int> inqueue;
struct tree{
	int data;
	tree * lchild=NULL;
	tree * rchild=NULL;
};
tree * createfront(int postfront,int postend,int infront,int inend,int post[],int in[]){
	if(postfront>postend||infront>inend) return NULL;
	if(postfront==postend&&infront==inend){
		tree * leave=new tree;
		leave->data=post[postend];
		leave->lchild=NULL;
		leave->rchild=NULL;
		return leave;
	}
	int chroot=post[postend];
	int i;
	for(i=postfront;i<=postend;i++) if(in[i]==chroot) break;
	tree * BT=new tree;
	BT->data=chroot;
	BT->lchild=createfront(postfront,postfront+i-infront-1,infront,i-1,post,in);
	BT->rchild=createfront(postend+i-inend,postend-1,i+1,inend,post,in);
	return BT;
}
void pre(tree *BT){
	if(!BT) return;
	else{
		cout << BT->data << " ";
		pre(BT->lchild);
		pre(BT->rchild);
	}
}
int main(){
	int n;
	cin >> n;
	int post[n],in[n];
	for(int i=0;i<n;i++) cin >> post[i];
	for(int i=0;i<n;i++) cin >> in[i];
	tree * root=new tree;
	root=createfront(0,n-1,0,n-1,post,in);
	pre(root);
	return 0;
}