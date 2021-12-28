#include <bits/stdc++.h>
using namespace std;
typedef struct BTNode {
    int data;
    struct BTNode *lnode, *rnode;
} BTNode, *BTree;
BTree createBT() {
    int data;
    BTree bt;
    scanf("%d", &data);
    if (data == 0) bt = NULL;
    else {
        bt = (BTree)malloc(sizeof(BTNode));
        bt->data = data;
        bt->lnode = createBT();
        bt->rnode = createBT();
    }
    return bt;
}
int tot[110] = {0};
int idx = 1;
void compute(BTree T)
{
    if (T) {
        if (T->lnode == NULL && T->rnode == NULL) {
            tot[idx] += T->data;
        }
        compute(T->lnode);
        compute(T->rnode);
        if (T->lnode != NULL && T->rnode != NULL) idx++;
    }
    return;
}
int getAns(int maxn)
{
    int ans = tot[0];
    int idx = 0;
    for (int i = 1; i < maxn; i++) {
        if (ans <= tot[i]) ans = tot[i], idx = i;
    }
    return idx;
}
int main()
{
    BTree T = NULL;
    T = createBT();
    if (T->lnode == NULL && T->rnode == NULL) {
        cout << "0" << endl;
    } else {
        compute(T);
        int ans = getAns(idx);
        cout << ans << endl;
    }
    return 0;
}