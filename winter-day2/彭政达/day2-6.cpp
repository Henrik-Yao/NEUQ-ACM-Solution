/* 
7-6 先序和中序构造二叉树
本题目要求用先序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其后序序列。
输入格式:
在第一行中输入元素个数。
第二行中输入先序序列，用空格分隔。
第三行中输入中序序列，用空格分隔。
输出格式:
输出此二叉树的后序序列，用空格分隔，最后也有一个空格。
输入样例:
5
10 20 30 40 50
20 10 40 30 50
输出样例:
20 40 50 30 10 
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
btnode *build(int *front,int *middle,int n){
    if(n==0) return NULL;
    int val=front[0];
    int i=get(front,middle, n);
    tree r=(tree)malloc(sizeof(node));
    r->value=val; 
    r->left=build(front+1,middle,i);
    r->right=build(front+i+1,middle+i+1,n-i-1);
    return r;
}
void postorder(tree root){  
    if(root){  
        postorder(root->left);  
        postorder(root->right);  
        cout<<root->value<<" ";  
    }  
}  
int main(){
	int a[15],b[15],n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
    tree root=build(a,b,n);
    postorder(root);
    cout<<endl;
}
