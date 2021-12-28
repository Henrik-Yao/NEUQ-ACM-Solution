#include <iostream>
#include <queue>
using namespace std;
typedef struct tr
{
    int data;
    tr* left = NULL;
    tr* right = NULL;
}tr;
int fer[120], mer[120];
tr* x = new tr;
tr* by(int l1, int r1, int l2, int r2)
{
    tr* t = new tr;
    if (l1 > r1 || l2 > r2)
        return NULL;
    else if (l1 == r1 && r2 == l2)
    {
        t->data = fer[l1];
        t->left = NULL;
        t->right = NULL;
    }
    else
    {
        int root = fer[l1];
        t->data = root;
        int i;
        for (i = l2; i <= r2; i++)
        {
            if (mer[i] == root)
            {
                break;
            }
        }
        if (i == l2)
        {
            t->right = by(l1 + i + 1 - l2, r1, i + 1, r2);
        }
        else if (i == r2)
        {
            t->left = by(l1 + 1, i + l1 - l2, l2, i - 1);
        }
        else
        {
            t->left = by(l1 + 1, l1 + i - l2, l2, i - 1);
            t->right = by(l1 + i + 1 - l2, r1, i + 1, r2);
        }
    }
    return t;

}

int main()
{
    int n;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> fer[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> mer[i];
    }
    tr* p = by(0, n - 1, 0, n - 1);
    queue<tr*>q;
    q.push(p);
    while (!q.empty())
    {
        tr* now = q.front();
        if (now)
        {
            cout << now->data << " ";
            q.push(now->left);
            q.push(now->right);
        }
        q.pop();
    }
    return 0;
}