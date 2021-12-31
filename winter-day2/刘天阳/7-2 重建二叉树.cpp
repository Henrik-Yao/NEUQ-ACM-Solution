#include <bits/stdc++.h>
using namespace std;
bool ju = 1;
struct Node{
	Node *l, *r;
	char val;
	Node(){
		l = r = NULL;
	}
};
int find(char *a, char c,int n){
	for (int i = 0; i < n; i++){
		if(c == a[i]){
			return i;
		}
	}
	return -1;
}
Node* BuildTree(int n, char *a, char *b)  //a为中序， b为后序
{
	if(n<=0 || ju==0) return NULL;  //注意有可能n小于0，所以不要使用if（!n) 
	Node *x;
	x = new Node;
	x->val = b[n-1];   //根为后续最后一个
	int t = find(a, b[n-1],n); //在中序中找到跟的位置  左右分别为左右子树
	if(t == -1) {
		ju = 0;
		return NULL;
	}
	x->l = BuildTree(t, a, b);  //因为初始为0所以t的位置即为长度
	x->r = BuildTree(n-t-1, a+t+1,b+t); //中序将左子树（t）和跟（1）去掉，后续将左子树去掉（t），跟的话在最右面，由n决定
	return x;                  
} 
int ans = 0;
void qian(Node *root,int t){
	if(root == NULL) return;
	cout << root->val;
	qian(root->l, t+1);
	qian(root->r, t+1);
}
void anss(Node *root,int t){
	if(root == NULL) return;
	if(t > ans) ans = t;
	anss(root->l, t+1);
	anss(root->r, t+1);
}
int main()
{
	char a[110], b[110];
    while(~scanf("%s%s", b, a)){
    	ju = 1;
        Node *root = BuildTree(strlen(b), a, b);
        if(ju){
        	anss(root, 0);
    	    cout << ans << endl;
    	    qian(root, 1);cout << endl;
		}
		else cout << "INVALID" << endl;
    }
	return 0;
}
