#include <bits/stdc++.h>
using namespace std;
struct Bnode {
    int data;
    Bnode* lnode = NULL;
    Bnode* rnode = NULL;
};
int T;
int head;
vector<int> a;
queue<int> q;
Bnode* create(int idx)
{
    if (idx >= a.size() || a[idx] == 0) return NULL;
    Bnode* root = new Bnode;
    root->data = a[idx];
    root->lnode = create(idx * 2);
    root->rnode = create(idx * 2 + 1);
    return root;
}
// InOrder
// 是否是第一次输出
int flag = 1;
void InOrder(Bnode* root)
{
    if (root->lnode != NULL) InOrder(root->lnode);
    if (root != NULL) {
        flag == 1 ? printf("%d", root->data), flag = 0 : printf(" %d", root->data);
    }
    if (root->rnode != NULL) InOrder(root->rnode);
}
int depth = 0;
// getDepth
void getDepth(Bnode* root, int nowDepth)
{
    if (root == NULL) return;
    depth = max(depth, nowDepth);
    getDepth(root->lnode, nowDepth + 1);
    getDepth(root->rnode, nowDepth + 1);
}
int main()
{
    cin >> T;
    while (T--) {
        cin >> head;
        a.push_back(-1);
        for (int i = 0; i < head; i++) {
            int num;
            cin >> num;
            a.push_back(num);
        }
        for (int i = 0; i < head; i++) {
            q.push(a[i]);
        }
        Bnode* root = new Bnode;
        root = create(1);
        getDepth(root, 1);
        InOrder(root);
        cout << endl << depth << endl;
        a.clear(); depth = 0; flag = 1; // 状态初始化
    }
    return 0;
}