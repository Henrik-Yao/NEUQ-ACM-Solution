#include <bits/stdc++.h>
using namespace std;

int inner[15];
int pre[15];
int n;
struct Bnode {
	int data;
	Bnode *lnode;
	Bnode *rnode; 
};
Bnode* create(int preL, int preR, int innerL, int innerR){
	if(preL > preR) return NULL;
	Bnode *root = new Bnode;
	root->data = pre[preL];
	int i;
	for(i = innerL; i <= innerR; i++) {
		if(inner[i] == pre[preL]) break;
	}
	int leftN = i - innerL;
	root->lnode = create(preL + 1,preL + leftN, innerL, i - 1);
	root->rnode = create(preL + leftN + 1, preR, i + 1, innerR);	
	return root;
}
//inOrder
void inOrder(Bnode* root){
	if (root->lnode != NULL) inOrder(root->lnode);
    printf("%d ", root->data);
    if (root->rnode != NULL) inOrder(root->rnode);
}
// PostOrder
void PostOrder(Bnode* root) {
    if (root->lnode != NULL) PostOrder(root->lnode);
    if (root->rnode != NULL) PostOrder(root->rnode);
    printf("%d ", root->data);
}
// PreOrder
void PreOrder(Bnode* root) {
    printf("%d ", root->data);
    if (root->lnode != NULL) PreOrder(root->lnode);
    if (root->rnode != NULL) PreOrder(root->rnode);
}
// FloorOrder
void FloorOrder(Bnode* root) {
    queue<Bnode*> q;
    q.push(root);
    while (!q.empty()) {
        // 取出将要输出的节点 并把下一层也就是左右子节点入队
        Bnode* front = q.front();
        q.pop();
        // 先输出再入队左右子节点
        printf("%d ", front->data);
        if (front->lnode != NULL) q.push(front->lnode);
        if (front->rnode != NULL) q.push(front->rnode);
    }
}
int main(){
	cin >> n;
	int i;
	for(i = 0; i < n; i++) cin >> pre[i];
	for(i = 0; i < n; i++) cin >> inner[i];
	Bnode *root;
	root = create(0, n - 1, 0, n - 1);
    FloorOrder(root);
}