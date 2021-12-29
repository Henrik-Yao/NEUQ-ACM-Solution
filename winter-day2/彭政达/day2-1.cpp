/*
7-1 二叉树叶结点值和最大层
已知一棵非空二叉树结点的数据域为不等于0的整数，请编写程序找出该二叉树中叶结点数据值之和最大的层。
输入格式:
输入为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列。
输出格式:
输出为一个整数，表示叶结点数据值之和最大的层，如果存在多个满足条件的层，则输出最下面一层。
输入样例1:
1 2 0 0 3 0 0
输出样例1
1
输入样例2:
1 -2 0 0 3 -1 0 0 -1 0 0
输出样例2:
2
*/
#include <bits/stdc++.h>
using namespace std;
int b[100]={0};
typedef struct node{
    int value;
    struct node *left, *right;
}*tree;
tree cr(){
    int Data;
    tree node;
    cin>>Data;
    if(!Data) node=NULL;
    else{
        n=(linknode)malloc(sizeof(node));
        n->data=Data;
        n->lchild=cr();
        n->rchild=cr();
    }
    return n;
}
int sum=0,x=1;
void f(tree n){
    if(n){
        if(!n->left && !n->right) b[x]+=n->data;
        f(n->lfet);f(n->right);
        if(n->left && n->right) x++;
    }
}
int compare(int *a,int k){
    int temp=a[0],l=0;
    for(int i=1;i<k;i++)
        if(temp<=a[i]){
            temp=a[i];l=i;
        }
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    tree a=NULL;
    a=cr();f(a);
    cout<<compare(b,x)<<endl;
    return 0;
}

