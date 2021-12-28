/*
7-8 中序遍历二叉树
按完全二叉树的层次遍历给出一棵二叉树的遍历序列（其中用0表示虚结点），
要求输出该二叉树的深度及中序遍历该二叉树得到的序列。
输入格式:
首先输入一个整数T，表示测试数据的组数，然后是T组测试数据。
每组测试数据首先输入一个正整数n（n≤1000），代表给出的二叉树的结点总数
（当然，其中可能包含虚结点）。结点编号均为正整数,且各不相同。 
然后输入n个正整数，表示按完全二叉树（即第1层1个结点，第2层2个，第3层4个，第4层有8个……）
的层次遍历给出的二叉树遍历序列，如果某个结点不存在（虚结点），则以0代替。
输出格式:
对于每组测试，第一行输出中序遍历二叉树得到的序列（每两个数据之间留一个空格），
第二行输出二叉树的深度。
输入样例:
2
1 1
4 1 4 0 2
输出样例:
1
1
2 4 1
3
*/
#include <bits/stdc++.h>
using namespace std;
int s=0;
typedef struct node{
    int value;
    node *left,*right;
}*tree;
tree createnode(){
    node *n=new node;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void cr(tree &root, int numbers[], int len){
    if(len==0) return;
    else{
        queue<tree> q;
        int i=0;
        root=createNode();
        root->value=numbers[i++];
        q.push(root);
        while(!q.empty()){
            tree temp=q.front();
            q.pop();
            if(i<len){s++;
                if(numbers[i]!=0){
                    temp->left=createNode();
                    temp->left->value=numbers[i];
                    q.push(temp->left);
                }
                i++;
            }
            if(i<len){
                if(numbers[i]!=0){s++;
                    temp->right=createNode();
                    temp->right->value=numbers[i];
                    q.push(temp->right);
                }
                i++;
            }
        }
    }
}
void preOrder(tree root){
    if(root){
        preOrder(root->left);
        if(root->value) cout<<root->value;
        if(s--) cout<<" ";
        preOrder(root->right);
    }
}
int getheight(tree root){
	if(root){
		int r=getheight(root->right);
		int l=getheight(root->left);
		return 1+(r>l?r:l);
	}
	else return 0;
}
int main(){
    int t;
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
    	s=0;
    	int num[1005],len;
    	cin>>len;
    	for(int i=0;i<len;i++) cin>>num[i];
    	tree r=NULL;
    	cr(r,num,len);
    	preOrder(r);
    	cout<<endl<<getheight(r)<<endl;
    }
}

