#include <bits/stdc++.h>
using namespace std;
int layer;
typedef struct treeNode
{
    int data;
    struct treeNode *lchild, *rchild;

} TREE, *LPTREE;
int getdeep(LPTREE t)
{
    int l, r;
    if (t == NULL)
        return 0;
    else
    {
        l = getdeep(t->lchild);
        r = getdeep(t->rchild);
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
}
LPTREE createNode(int tdata)
{
    LPTREE newNode = (LPTREE)malloc(sizeof(TREE));
    if (!tdata)
    {
        newNode = NULL;
        return newNode;
    }
    else
    {
        newNode->data = tdata;
        newNode->lchild = NULL;
        newNode->rchild = NULL;
    }
    return newNode;
}
void mergelchild(LPTREE parent, LPTREE lchild)
{
    parent->lchild = lchild;
}
void mergerchild(LPTREE parent, LPTREE rchild)
{
    parent->rchild = rchild;
}
bool sign = 0;
void zhongxu(LPTREE root)
{
    if (root != NULL)
    {
        zhongxu(root->lchild);
        if (!sign && layer)
        {
            cout << root->data;
            sign = 1;
        }
        else if (sign && layer)
        {
            cout << " " << root->data;
        }
        zhongxu(root->rchild);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, tempdata, num;
    cin >> T;
    while (T--)
    {
        cin >> num;
        LPTREE tree[num + 1];
        layer = ceil(log2(num + 1));
        for (int i = 1; i <= num; ++i)
        {
            cin >> tempdata;
            tree[i] = createNode(tempdata);
            if (i == 1 && (!tempdata))
            {
                layer = 0;
            }
            if (i > 1 && tempdata && (i / 2))
            {
                if (i % 2)
                    mergerchild(tree[i / 2], tree[i]);
                else
                    mergelchild(tree[i / 2], tree[i]);
            }
        }
        zhongxu(tree[1]);
        if (layer)
            cout << endl;
        cout << getdeep(tree[1]) << endl;
        sign = 0;
    }
    return 0;
}
