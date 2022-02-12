#include <bits/stdc++.h>
using namespace std;
#define emp 0

vector<int>ans;
struct Node{
	int value;
	Node *left,*right;
};

Node *CreateNode(){
	Node *node = new Node;
	node -> left = node -> right = NULL;
	return node;
}

void CreateBiTree(Node *&root,int num[],int len,int i){
	if(i <= len){
		root -> value = num[i - 1];
		if(i * 2 <= len && num[i * 2 - 1] != emp){
			root -> left = CreateNode();	
			CreateBiTree(root -> left,num,len,i * 2);
		}
		if((i * 2 + 1) <= len && num[i * 2] != emp){
			root -> right = CreateNode();
			CreateBiTree(root -> right,num,len,i * 2 + 1);
		}
	}
}

int getheight(Node *&root){
	if(!root)return 0;
	return (getheight(root -> left) > getheight(root -> right) ? getheight(root -> left) : getheight(root -> right)) + 1;
}

void inorder(Node *&root){
	if(!root)return;
	inorder(root -> left);
	ans.push_back(root -> value);
	inorder(root -> right);
}

int main(){
	int num[1001] = {};
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)scanf("%d",&num[i]);
		Node *root = CreateNode();
		CreateBiTree(root,num,n,1);
		inorder(root);
		for(int i = 0;i < ans.size() - 1;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[ans.size() - 1]);
		printf("%d\n",getheight(root));
		delete root;
		ans.clear();
	}
	return 0;
}