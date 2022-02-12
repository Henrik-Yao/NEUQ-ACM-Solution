#include <bits/stdc++.h>
using namespace std;
typedef struct treeNode
{
    int data;
    struct treeNode *lchild, *rchild;
    int layer;
} TREE, *LPTREE;
int sum[105];
int maxlayer = 0;
LPTREE createNode(int lay)
{
    int data;
    cin >> data;

    LPTREE newNode;
    if (!data)
    {
        newNode = NULL;
    }
    else
    {
        newNode = (LPTREE)malloc(sizeof(TREE));
        newNode->data = data;
        newNode->layer = lay + 1;
        newNode->lchild = createNode(newNode->layer);
        newNode->rchild = createNode(newNode->layer);
        if (newNode->layer > maxlayer)
        {
            maxlayer = newNode->layer;
        }
        sum[newNode->layer] += newNode->data;
    }

    return newNode;
}
int k = 1;
void sumup(LPTREE T)
{
    if (T)
    {

        if (T->lchild == NULL && T->rchild == NULL)
            sum[k] += T->data;

        sumup(T->lchild);
        sumup(T->rchild);
        if (T->lchild != NULL && T->rchild != NULL)
            k++;
    }
    return;
}

int compare(int *a, int x)
{
    int i, j, temp = sum[0], l = 0;
    for (j = 1; j < x; j++)
    {
        if (temp <= sum[j])
        {
            temp = sum[j];
            l = j;
        }
    }

    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(sum, 0, sizeof(sum));
    LPTREE tree = createNode(0);
    sumup(tree);
    // int maxsum, maxlay;
    // for (int i = 1; i <= maxlayer; ++i)
    // {
    //     if (i == 1)
    //     {
    //         maxsum = sum[i];
    //         maxlay = i;
    //     }
    //     else
    //     {
    //         if (sum[i] >= maxsum)
    //         {
    //             maxsum = sum[i];
    //             maxlay = i;
    //         }
    //     }
    // }
    int l = compare(sum, k);
    cout << l << endl;

    return 0;
}
