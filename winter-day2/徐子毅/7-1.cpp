#include <iostream>
using namespace std;
struct tree{
	int data;
	tree * lchild;
	tree * rchild;
	int level;
};
int sum[105];
int num[105];
int maxlevel=-1;
tree * createtree(int level){
	int n;
	cin >> n;
	if(n==0) return NULL;
	else{
		tree * BT = new tree;
		BT->data=n;
		BT->level=level;
		if(level>maxlevel) maxlevel=level;
		BT->lchild=createtree(level+1);
		BT->rchild=createtree(level+1);
		return BT;
	}
}
void GETBEST(tree * BT){
	if(BT==NULL) return;
	else{
		if(BT->lchild==NULL&&BT->rchild==NULL){
			sum[BT->level]+=BT->data;
			num[BT->level]++;
		}
		GETBEST(BT->lchild);
		GETBEST(BT->rchild);
	}
}
int main(){
	tree * root=createtree(0);
	GETBEST(root);
	int _max_SUM=-9999;int goodlevel=0;
	for(int i=0;i<=maxlevel;i++){
		if(sum[i]>=_max_SUM&&num[i]){
			_max_SUM=sum[i];
			goodlevel=i;
		}
	}
	cout << goodlevel << endl;
	return 0;
}