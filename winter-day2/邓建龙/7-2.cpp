#include<bits/stdc++.h>
using namespace std;
vector<char> back;
vector<char> inner;
struct Bnode{
    char ch;
    Bnode *lchild=NULL;
    Bnode *rchild=NULL;
};
Bnode *create(int backL,int backR,int innerL,int innerR){
    if(backL>backR) {
        return NULL;
    }
    Bnode *root = new Bnode;
    root->ch = back[backR];  // A
    int i; // 2
    int flag = 0;
    for(i = innerL; i <= innerR; i++) { //1 - 3
        if (inner[i] == back[backR]) {
            flag = 1; // 正常
            break;
        }
    }
    if (flag == 1) {
        int leftN = i - innerL; // 1
        root->lchild = create(backL, backL + leftN - 1, innerL, i - 1); // 1 1 1 1
        root->rchild = create(backL + leftN, backR - 1, i + 1, innerR); // 2, 2, 3,  3
        return root;    
    } else {
        return NULL;
    }
    
}
void PreOrderTraverse(Bnode *root) {
    if (root == NULL) return;
    printf("%c", root->ch);
    PreOrderTraverse(root->lchild);
    PreOrderTraverse(root->rchild);
}
int depth = 0;
void getDepth(Bnode *root, int nowDepth) {
    if (root == NULL) return;
    depth = max(depth, nowDepth);
    getDepth(root->lchild, nowDepth + 1);
    getDepth(root->rchild, nowDepth + 1);
}
int num = 0;
void getNum(Bnode *root)
{
    if (root == NULL) return;
    num++;
    getNum(root->lchild);
    getNum(root->rchild);
}
int main(){
    string a1, a2;
    while (cin >> a1 >> a2) {
        back.push_back(' '), inner.push_back(' ');
        for (int i = 0; i < a1.size(); i++) back.push_back(a1[i]);
        for (int i = 0; i < a2.size(); i++) inner.push_back(a2[i]);
        int len = a1.size();
        Bnode *root = create(1, len, 1, len);
        getDepth(root, 0);
        getNum(root);
        if (num == back.size() - 1) {
            cout << depth << endl;
            PreOrderTraverse(root);
            cout << endl;
        } else {
            cout << "INVALID" << endl;
        }
        back.clear();
        inner.clear();
        depth = 0;
        num = 0;
    }
    return 0;
}