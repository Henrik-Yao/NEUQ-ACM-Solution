#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int in[N],pre[N];
typedef struct Node{
    int data;
    Node *left,*right;
}*BitTree;

BitTree creat(int in[],int pre[],int n){
    if(n < 1)
        return NULL;
    BitTree tree = new Node();
    tree->data = pre[0];
    tree->left = tree->right = NULL;
    int i;
    for(i=0; i<n; i++){
        if(pre[0] == in[i])
            break;
    }
    tree->left = creat(in, pre+1, i);
    tree->right = creat(in+i+1, pre+i+1, n-i-1);
    return tree;
}

void print(BitTree tree){
    if(!tree)
        return;
    deque<BitTree> deq;
    deq.push_back(tree);
    while(!deq.empty()){
        cout << deq.front()->data << " ";
        if(deq.front()->left != NULL){
            deq.push_back(deq.front()->left);
        }
        if(deq.front()->right != NULL){
            deq.push_back(deq.front()->right);
        }
        deq.pop_front();
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> pre[i];
    }
    for(int i=0; i<n; i++){
        cin >> in[i];
    }
    BitTree tree = creat(in,pre,n);
    print(tree);
    return 0;
}
