/*
7-7 按层遍历二叉树
用先序和中序序列构造一棵二叉树（树中结点个数不超过10个），
通过用队记录结点访问次序的方法实现对二叉树进行按层遍历，
即按层数由小到大、同层由左到右输出按层遍历序列。
输入格式:
第一行输入元素个数
第二行输入先序序列，以空格隔开
第三行输入中序序列，以空格隔开
输出格式:
输出此二叉树的按层遍历序列，以空格隔开，最后也有一个空格。
输入样例:
5
10 20 40 30 50
20 40 10 50 30
输出样例:
10 20 30 40 50 
*/
#include <bits/stdc++.h>
using namespace std; 
typedef struct node{
    int value;
    struct node *left,*right;
}*tree;
int get(int *front,int *middle, int n){
    int i,ch;
    for(i=0,ch=front[0];i<n;i++)
        if(middle[i]==ch) return i;
    return -1;
}
tree build(int *front,int *middle,int n){
    if(n==0) return NULL;
    int val=front[0];
    int i=get(front,middle, n);
    node *r=(tree)malloc(sizeof(node));
    r->value=root_val; 
    r->left=build(front+1,middle,i);
    r->right=build(front+i+1,middle+i+1,n-i-1);
    return r;
}
void postorder(tree root){  
    tree pt;
    queue<tree> q;
    if(root==NULL) return ;
    q.push(root);
    while(!q.empty() && q.front()){
    	cout<<q.front()->value<<" ";
    	if(q.front()->left!=NULL) q.push(q.front()->left);
    	if(q.front()->right!=NULL) q.push(q.front()->right);
    	q.pop();
	}
}
int main(){
	int a[15],b[15],n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
    node *root=build(a,b,n);
    postorder(root);
    cout<<endl;
}
