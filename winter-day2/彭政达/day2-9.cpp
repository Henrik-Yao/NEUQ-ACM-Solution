/*
7-9 后序和中序构造二叉树
本题目要求用后序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其先序序列。
输入格式:
在第一行中输入元素个数。
第二行中输入后序序列，用空格分隔。
第三行中输入中序序列，用空格分隔。
输出格式:
输出此二叉树的先序序列，用空格分隔，最后也有一个空格。
输入样例:
5
20 40 50 30 10
20 10 40 30 50
输出样例:
10 20 30 40 50 
      10                    
  20    30                      
      40  50                   
*/
#include <bits/stdc++.h>
using namespace std; 
typedef struct node{
    int value;
    struct node *left,*right;
}*tree;
void cr(tree& t, int* back, int* middle, int n){
    int num;
    int* ptr;
    if (n<=0){
        t=NULL;
        return;
    }
    t=new node;
    ptr=middle;
    while (*ptr != back[n - 1]) ptr++;
    t->value= *ptr;
    num=ptr-middle;
    cr(t->left,back,middle,num);
    cr(t->right,back+num,middle+num+1,n-num -1);
}
void postorder(tree root){  
    if(root!=NULL){
    	cout<<root->value<<" ";
    	postorder(root->left);
    	postorder(root->right);
	}
}
int main(){
	int a[15],b[15],n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
    tree root;
	cr(root,a,b,n);
    postorder(root);
    cout<<endl;
}
