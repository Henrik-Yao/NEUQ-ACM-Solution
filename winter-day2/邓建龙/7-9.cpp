#include <bits/stdc++.h>
using namespace std;
int n;
int inner[15], back[15];
struct Bnode {
    int data;
    Bnode* lnode = NULL;
    Bnode* rnode = NULL;
};
Bnode* create(int backL, int backR, int innerL, int innerR) {
    // 返回条件
    if (backL > backR) return NULL;
    Bnode* root = new Bnode;
    root->data = back[backR];
    int i;
    for (i = innerL; i <= innerR; i++) {
        if (inner[i] == back[backR]) break;
    }
    int leftN = i - innerL;
    root->lnode = create(backL, backL + leftN - 1, innerL, i - 1);
    root->rnode = create(backL + leftN, backR - 1, i + 1, innerR);
    return root;
}
// PreOrder
void PreOrder(Bnode* root)
{
    printf("%d ", root->data);
    if (root->lnode != NULL) PreOrder(root->lnode);
    if (root->rnode != NULL) PreOrder(root->rnode);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> back[i];
    for (int i = 0; i < n; i++) cin >> inner[i];
    Bnode* root;
    root = create(0, n - 1, 0, n - 1);
    PreOrder(root);
    return 0;
}