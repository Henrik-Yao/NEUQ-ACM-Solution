​                                                                                  day2题解

1.思路：根据前序序列创建树；递归求每一层叶子节点的和，用一个数组存每一层的和，数字下标对应第几层， 遍历数组，找出最大值对应的那个下标。

#include<iostream>

using namespace std;
int b[100] = { 0 };


typedef struct tree
{
	int data;
	struct tree* zuo, * you;
}tree, *xianjd;



xianjd setbetree() {
	int sh;
	xianjd node;
	cin >> sh;
	if (sh == 0) {
		node = NULL;
	}
	else {
		node = (xianjd)malloc(sizeof(tree));
		node->data = sh;
		node->zuo = setbetree();
		node->you = setbetree();
	}
	return node;
}

int sum = 0;
int i = 1;


void P(xianjd pd) {
	if (pd) {

		if (pd->zuo == NULL && pd->you == NULL)
			b[i] += pd->data;
	
		P(pd->zuo);
		P(pd->you);
		if (pd->zuo != NULL && pd->you != NULL)
			i++;
	}
	return;
}


int  compare(int* a, int k) 
{
	int i, j, temp = a[0], l = 0;
	for (j = 1; j < k; j++)
	{
		if (temp <= a[j]) 
		{
			temp = a[j];
			l = j;
		}
	}

	return l;
}





int main() {

	xianjd T = NULL;
	T = setbetree();
	
	if (T->zuo == NULL && T->you == NULL) 
	{ cout << "0"; return 0; }
	P(T);
	
	int l = compare(b, i);
	
	cout << l << endl;
	
	return 0;
}

6，7，8，9

思路：树状数组本身是用左儿子和父本来表示右儿子，其本身可以减少每层对应的数据遍历数，极大的提升效率，难点是用链表和树状数组联系起来。

6#include <iostream>
using namespace std;
typedef struct tr
{
    int data;
    tr* left = NULL;
    tr* right = NULL;
}tr;
int a[120], r[120];
tr* x = new tr;
tr* by(int l1, int r1, int l2, int r2)
{
    tr* t = new tr;
    if (l1 > r1 || l2 > r2)
        return NULL;
    else if (l1 == r1 && r2 == l2)
    {
        t->data = a[l1];
        t->left = NULL;
        t->right = NULL;
    }
    else
    {
        int root = a[l1];
        t->data = root;
        int i;
        for (i = l2; i <= r2; i++)
        {
            if (r[i] == root)
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
void dy(tr* p)
{
    if (p != NULL)
    {
       dy(p->left);
       dy(p->right);
        cout << p->data << " ";
    }
}
int main()
{
    int n;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    tr* p = by(0, n - 1, 0, n - 1);
    dy(p);
}

7#include <iostream>
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

8#include <iostream>
using namespace std;
typedef struct tr
{
    int data;
    tr* left;
    tr* right;
}tr;
int er[1001], csd= -1, sum = 0;
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
        csd= max(l, csd);
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
        cout << endl <<csd << endl;
    }
}

9#include <iostream>
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