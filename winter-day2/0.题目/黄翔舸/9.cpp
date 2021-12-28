#include <iostream>
using namespace std;
typedef struct tr
{
    int data;
    tr* left = NULL;
    tr* right = NULL;
}tr;
int f[120], m[120];
tr* x = new tr;
tr* by(int l1, int r1, int l2, int r2)
{
    tr* t = new tr;
    if (l1 > r1 || l2 > r2)
        return NULL;
    else if (l1 == r1 && r2 == l2)
    {
        t->data = f[r1];
        t->left = NULL;
        t->right = NULL;
    }
    else
    {
        int root = f[r1];
        t->data = root;
        int i;
        for (i = l2; i <= r2; i++)
        {
            if (m[i] == root)
            {
                break;
            }
        }
        if (i == l2)
        {
            t->right = by(l1 + i - l2, r1 - 1, i + 1, r2);
        }
        else if (i == r2)
        {
            t->left = by(l1, l1 + i - l2 - 1, l2, i - 1);
        }
        else
        {
            t->left = by(l1, l1 + i - l2 - 1, l2, i - 1);
            t->right = by(l1 + i - l2, r1 - 1, i + 1, r2);
        }
    }
    return t;

}
void dy(tr* p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        dy(p->left);
        dy(p->right);
    }
}
int main()
{
    int n;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    tr* p = by(0, n - 1, 0, n - 1);
    dy(p);
}