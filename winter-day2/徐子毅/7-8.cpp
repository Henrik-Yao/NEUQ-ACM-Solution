#include <iostream>
#include <vector>
using namespace std;
vector<int> inqueue;
struct tree{
	int data;
	tree * lchild=NULL;
	tree * rchild=NULL;
};
void INBT(tree *BT){
	if(!BT) return;
	else{
		INBT(BT->lchild);
		inqueue.push_back(BT->data);
		INBT(BT->rchild);
	}
}
int GETHIGH(tree *BT){
	if(!BT) return 0;
	else return max(GETHIGH(BT->lchild),GETHIGH(BT->rchild))+1;
}
int main(){
	int T;int n;int nums;
	cin >> T;
	for(int abcdefg=0;abcdefg<T;abcdefg++){
		cin >> n;
		tree * btree[n+1];
		for(int i=0;i<=n;i++) btree[i]=new tree;
		cin >> nums;
		btree[1]->data=nums;
		for(int i=2;i<=n;i++){
			int num;
			cin >> num;
			if(num!=0) {
				btree[i]->data=num;
				if(i%2==0) btree[i/2]->lchild=btree[i];
				else btree[i/2]->rchild=btree[i];
			}else{
				if(i%2==0) btree[i/2]->lchild=NULL;
				else btree[i/2]->rchild=NULL;
			}
		}
		inqueue.clear();
		INBT(btree[1]);
		if(!inqueue.empty()) cout << inqueue[0];
		for(int i=1;i<inqueue.size();i++) cout << " " << inqueue[i];
		cout << endl;
		// int level=1;int double2=2;
		// while(double2<=n){
		// 	level++;
		// 	double2*=2;
		// }
		cout << GETHIGH(btree[1]) << endl;
	}
}