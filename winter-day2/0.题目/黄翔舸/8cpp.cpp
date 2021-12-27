#include <iostream>
using namespace std;
typedef struct tr
{
    int data;
    tr* left;
    tr* right;
}tr;
int er[1001], csd = -1, sum = 0;
tr* bd(int n, int m, int l)
{

    tr* t = new tr;
    if (er[n] == 0)
    {
        t = NULL;
    }
    else
    {
        sum++;
        csd = max(l, csd);
        t->data = er[n];
        if (n * 2 <= m)
        {
            t->left = bd(n * 2, m, l + 1);
        }
        else
        {
            t->left = NULL;
        }
        if (n * 2 + 1 <= m)
        {
            t->right = bd(n * 2 + 1, m, l + 1);
        }
        else
        {
            t->right = NULL;
        }
    }
    return t;
}
int b = 0;
void count(tr* p)
{
    if (p)
    {
        count(p->left);
        count(p->right);
        b++;
    }
}
void dy(tr* p, int x)
{
    if (p != NULL)
    {
        dy(p->left, x);
        if (b == x - 1)
            cout << p->data;
        else
            cout << p->data << " ";
        b++;
        dy(p->right, x);

    }
}
int  main()
{
    int n;
    cin >> n;
    while (n--)
    {
        b = 0;
        sum = 0;
        csd = -1;
        int m;
        cin >> m;
        int i, j;
        for (j = 1; j <= m; j++)
        {
            cin >> er[j];
        }
        tr* p = bd(1, m, 1);
        int x = 0;
        count(p);
        x = b;
        b = 0;
        dy(p, x);
        cout << endl << csd << endl;
    }
}
