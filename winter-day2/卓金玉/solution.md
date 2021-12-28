# 寒假集训—day2(树)
## 7-1 二叉树叶节点值和最大层
### 题面
已知一棵非空二叉树结点的数据域为不等于0的整数，请编写程序找出该二叉树中叶结点数据值之和最大的层。
**输入格式:**
输入为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列。
**输出格式:**
输出为一个整数，表示叶结点数据值之和最大的层，如果存在多个满足条件的层，则输出最下面一层。

**输入样例:**
在这里给出一组输入。例如：
```
1 2 0 0 3 0 0
结尾无空行
```
**输出样例:**
在这里给出相应的输出。例如：
```
1
结尾无空行
```
### 思路
建树，定义sumup函数和compare函数，sumup函数把每层结点的数据加起来，compare函数是比较每层和的大小，并记录和最大的层数，输出

### 代码
```c++
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
    int l = compare(sum, k);
    cout << l << endl;

    return 0;
}

```
## 7-4 罪犯帮派
### 题面

Tabu市的警察局决定结束混乱，因此要采取行动根除城市中的几大帮派。目前的问题是，给出两个罪犯，他们是属于同一帮派么？城市里一共有多少个帮派？假设在Tabu市现有n名罪犯，编号为1到n，给出m条消息表示属于同一帮派的两个罪犯编号。请基于这些不完全的信息帮助警方计算出他们想要的信息。

**输入格式:**
输入第一行为三个正整数，n、m和q。n为罪犯数；m为给出的已知信息数量；q为查询数。接下来m行，每行2个正整数a和b，表示罪犯a和罪犯b属于同一帮派。接下来q行，每行2个正整数c和d，即查询罪犯c和d是否属于同一帮派。每行输入的整数以空格间隔，n、m、q均不超过1000。

**输出格式:**
输出为q+1行，前q行对应于输入的q个查询的结果，如果属于同一帮派，则输出“In the same gang.”，否则输出“In different gangs.”。最后一行为一个整数，表示帮派数目。

**输入样例:**
在这里给出一组输入。例如：
```
3 2 1
1 2
2 3
1 3
结尾无空行
```
**输出样例:**
在这里给出相应的输出。例如：
```
In the same gang.
1
结尾无空行
```
### 思路
这道题用的算法是并查集，~~现学现卖~~，计算并查集个数的方法是每合并一次就将总人数-1

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define N 1005
int gang[N];
int cnt;
int init()
{
    for (int i = 0; i < N; ++i)
    {
        gang[i] = i;
    }
}
int stand(int a)
{
    return gang[a] == a ? a : stand(gang[a]);
}
int merge(int a, int b)
{
    gang[stand(a)] = stand(b);
}
bool quest(int a, int b)
{
    return stand(a) == stand(b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    init();
    int a, b, qa, qb;
    cnt = n;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        merge(a, b);
        cnt--;
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> qa >> qb;
        if (quest(qa, qb))
        {
            cout << "In the same gang." << endl;
        }
        else
        {
            cout << "In different gangs." << endl;
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     // cout << "- - -" << endl
    //     //      << "gang[" << i << "] = " << gang[i] << endl;
    //     // for (int j = 1; j < i; ++j)
    //     // {

    //     // }
    //     if (!quest(i, 1))
    //     {
    //         cnt++;
    //     }
    // }
    cout << cnt << endl;
    return 0;
}

```

## 7-6 先序和中序构造二叉树
### 题面
本题目要求用先序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其后序序列。
**输入格式:**
在第一行中输入元素个数。
第二行中输入先序序列，用空格分隔。
第三行中输入中序序列，用空格分隔。
**输出格式:**
输出此二叉树的后序序列，用空格分隔，最后也有一个空格。
**输入样例:**
```
5
10 20 30 40 50
20 10 40 30 50
结尾无空行
```
**输出样例:**
```
20 40 50 30 10 
结尾无空行
```

### 思路
定义post函数求后序，不用建树，使用数组即可解决，参数是根和数组范围，即：每次函数的调用都是在找子树的根和分割数组进行分治的过程，分治结束后按照“左右根”的顺序打印结点

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int n;
int pre[15], in[15];
void post(int root, int l, int r)
{
    if (l > r)
    {
        return;
    }
    int i = l;
    while (i != r && in[i] != pre[root])
    {
        ++i;
    }
    post(root + 1, l, i - 1);
    post(root + 1 + i - l, i + 1, r);
    cout << pre[root] << " ";
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
    post(0, 0, n - 1);
    return 0;
}
```


## 7-7 按层遍历二叉树
### 题面
用先序和中序序列构造一棵二叉树（树中结点个数不超过10个），通过用队记录结点访问次序的方法实现对二叉树进行按层遍历，即按层数由小到大、同层由左到右输出按层遍历序列。

**输入格式:**
第一行输入元素个数
第二行输入先序序列，以空格隔开
第三行输入中序序列，以空格隔开

**输出格式:**
输出此二叉树的按层遍历序列，以空格隔开，最后也有一个空格。

**输入样例:**
```
5
10 20 40 30 50
20 40 10 50 30
结尾无空行
```
**输出样例:**

```
10 20 30 40 50 
结尾无空行
```

### 思路
本题需要建树，具体步骤是根据上题思路建立树结点，并且递归地把树根和树左右孩子连在一起，按层遍历可以建一个队列，从根开始入队并打印，打印过后出队，把结点的左右孩子入队，左结点出队打印之后把左结点的左孩子和右孩子入队排在右节点的后面，以此类推。
### 代码
```c++
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
```

## 7-8 中序遍历二叉树
### 题面
按完全二叉树的层次遍历给出一棵二叉树的遍历序列（其中用0表示虚结点），要求输出该二叉树的深度及中序遍历该二叉树得到的序列。
**输入格式:**
首先输入一个整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据首先输入一个正整数n（n≤1000），代表给出的二叉树的结点总数（当然，其中可能包含虚结点）。结点编号均为正整数,且各不相同。 然后输入n个正整数，表示按完全二叉树（即第1层1个结点，第2层2个，第3层4个，第4层有8个……）的层次遍历给出的二叉树遍历序列，如果某个结点不存在（虚结点），则以0代替。
**输出格式:**
对于每组测试，第一行输出中序遍历二叉树得到的序列（每两个数据之间留一个空格），第二行输出二叉树的深度。
**输入样例:**
```
2
1 1
4 1 4 0 2
结尾无空行
```
**输出样例:**
```
1
1
2 4 1
3
结尾无空行
```

### 思路
普通地建树结点，合并结点，不知道是不是计算层数的公式记错了，写的是
```layer = ceil(log2(num+1));```
wa了好多次~~于是去缝了一个计算深度的函数~~
### 代码
```c++
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
```
## 7-9 后序和中序构造二叉树
### 题面
本题目要求用后序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其先序序列。
**输入格式:**
在第一行中输入元素个数。
第二行中输入后序序列，用空格分隔。
第三行中输入中序序列，用空格分隔。
**输出格式:**
输出此二叉树的先序序列，用空格分隔，最后也有一个空格。
**输入样例:**
```
5
20 40 50 30 10
20 10 40 30 50
结尾无空行
```
**输出样例:**
```
10 20 30 40 50 
结尾无空行
```
### 思路
思路和前面那道前序题完全一样，就摸了
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int n;
int in[15], post[15];
void pre(int root, int l, int r)
{
    if (l > r)
        return;
    int i = l;
    while (i != r && in[i] != post[root])
    {
        ++i;
    }
    cout << post[root] << " ";
    pre(root - 1 - r + i, l, i - 1);
    pre(root - 1, i + 1, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> post[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i];
    }
    pre(n - 1, 0, n - 1);
    return 0;
}
```