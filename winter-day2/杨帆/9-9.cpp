#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int in[N],post[N];
typedef struct Node{
    int data;
    Node *left,*right;
}*BitTree;

BitTree create(int *post, int *in, int n) {
    if (n < 1)
        return NULL;
    BitTree tree = new Node();
    tree->data = post[n - 1];
    tree->left = tree->right = NULL;
    int i;
    for (i = 0; i < n; i++) {
        if (post[n - 1] == in[i])
            break;
    }
    tree->left = create(post, in, i);
    tree->right = create(post + i, in + i + 1, n - i - 1);
    return tree;
}

void preorder(BitTree tree) {
    if (!tree)
        return;
    cout << tree->data << " ";
    preorder(tree->left);
    preorder(tree->right);
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> post[i];
    }
    for(int i=0; i<n; i++){
        cin >> in[i];
    }
    BitTree tree = create(post,in,n);
    preorder(tree);
    return 0;
}
