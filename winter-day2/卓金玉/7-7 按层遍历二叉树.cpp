#include <bits/stdc++.h>
using namespace std;
int n;
int pre[15], in[15];
typedef struct treeNode
{
    int data;
    struct treeNode *lchild, *rchild;
} TREE, *LPTREE;
LPTREE creatNode(int root, int l, int r)
{
    if (l > r)
        return NULL;
    int i = l;
    while (i != r && in[i] != pre[root])
    {
        i++;
    }
    LPTREE t = (LPTREE)malloc(sizeof(TREE));
    t->lchild = creatNode(root + 1, l, i - 1);
    t->rchild = creatNode(root + 1 + i - l, i + 1, r);
    t->data = pre[root];
    return t;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i];
    }
    LPTREE tree = creatNode(0, 0, n - 1);

    queue<LPTREE> q;
    q.push(tree);
    LPTREE t = tree;
    while (!q.empty() && t != NULL)
    {
        t = q.front();
        q.pop();
        cout << t->data << " ";
        if (t->lchild != NULL)
        {
            q.push(t->lchild);
        }
        if (t->rchild != NULL)
        {
            q.push(t->rchild);
        }
    }
    // for(auto it : q)
    // {
    //     cout<<
    // }
    return 0;
}
