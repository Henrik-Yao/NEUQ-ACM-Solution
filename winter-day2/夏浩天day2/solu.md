## 7-1 二叉树叶结点值和最大层

已知一棵非空二叉树结点的数据域为不等于0的整数，请编写程序找出该二叉树中叶结点数据值之和最大的层。

一道用来熟悉~~？~~二叉树的题

~~~#include<iostream>
#include<iostream>
#include<stdlib.h> 
using namespace std;
int sum[100];//和
int cs = 1;//层数

struct TT
{
	int data;
	struct TT* lc, * rc;
};

TT* createtree()
{
	int data;
	TT* T1;
	cin >> data;
	if (!data)T1 = NULL;
	else
	{
		T1 = (TT*)malloc(sizeof(TT));
		T1->data = data;
		T1->lc = createtree();
		T1->rc = createtree();
	}
	return T1;
}

void P(TT* B)
{
	if (B)//如果B不为NULL
	{
		if (!B->lc && !B->rc)//没娃
			sum[cs] += B->data;
		P(B->lc);
		P(B->rc);
		if (B->lc && B->rc)cs++;
	}
}

int main()
{
	TT* T = NULL;
	T = createtree();

	if (T->lc == NULL && T->rc == NULL)//没娃
	{
		cout << "0";
	}
	else
	{
		P(T);
		int he = 0, c = 0;
		for (int i = 0; i < cs; i++)
			if (sum[i] >= he)
			{
				he = sum[i];
				c = i;
			}
		cout << c;
	}
}
~~~



## 7-2 重建二叉树

给定非空二叉树的中根序列和后根序列，请编写程序创建该二叉树，计算其高度和先根序列，最后删除该二叉树；如给定的中根和后根序列不合法，则亦能识别。

依据中根序列和后根序列建数并存下先序

~~~#include<iostream>
using namespace std;
typedef struct tree
{
	tree* lc;
	tree* rc;
};
string fir = "";
bool istree;
tree* postorder(char post[], char mid[], int n)
{
	if (n == 0) return NULL;
	tree* bt = new tree;
	int i;
	for (i = 0; i < n; i++)
		if (post[n - 1] == mid[i]) break;
	if (i == n)
	{
		istree = 0;
		return NULL;
	}
	fir += post[n - 1];
	bt->lc = postorder(post, mid, i);
	bt->rc = postorder(post + i, mid + i + 1, n - i - 1);
	return bt;
}
int getheight(tree* bt)
{
	if (!bt) return 0;
	return max(getheight(bt->lc), getheight(bt->rc)) + 1;
}
int main()
{
	string s1,s2;
	while (cin >> s1 >> s2)
	{
		istree = 1;
		int n = s1.size();
		char post[10001], mid[10001];
		for (int i = 0; i < n; i++) 	post[i] = s1[i];
		for (int i = 0; i < n; i++)     mid[i] = s2[i];
		tree* bt = postorder(post, mid, n);

		if (istree)
		{
			cout << getheight(bt) - 1 << endl;
			cout << fir;
		}
		else cout << "INVALID";
		cout << endl;
		fir = "";
	}
	return 0;
}
~~~

## 7-3 树最近公共祖先

已知树结点为互不相等且不等于0的整数。请编写程序找出非空树中两个结点的最近公共祖先。例如对于图1(a)所示的树t，结点1和2的最近公共祖先是5；结点2和4的最近公共祖先是8。



## 7-4 罪犯帮派

Tabu市的警察局决定结束混乱，因此要采取行动根除城市中的几大帮派。目前的问题是，给出两个罪犯，他们是属于同一帮派么？城市里一共有多少个帮派？假设在Tabu市现有n名罪犯，编号为1到n，给出m条消息表示属于同一帮派的两个罪犯编号。请基于这些不完全的信息帮助警方计算出他们想要的信息。

错误代码：

~~~#include<iostream>
#include<stdlib.h> 
#include<vector>
using namespace std;
int bh[1001];
int sm = 1;
int sm_ = 0;//重复的团队量
vector<int> team[1001];//储存某团队中所有人编号
int main()
{
	int n, m, q; cin >> n >> m >> q;
	while (m--)
	{
		int a, b; cin >> a >> b;
		if (bh[a] && !bh[b])
		{
			bh[b] = bh[a]; team[bh[a]].push_back(b);
		}
		else if (bh[b] && !bh[a])
		{
			bh[a] = bh[b]; team[bh[b]].push_back(a);
		}
		else if (bh[a] && bh[b] && bh[a] != bh[b])
		{
			int l = bh[a];
			while (!team[l].empty())
			{
				team[bh[b]].push_back(team[l].back());//合并团队a->b
				bh[team[l].back()] = bh[b];//确认团队编号
				team[l].pop_back();
			}
			sm_++;
		}
		else if (bh[a] == bh[b])continue;
		else { bh[a] = sm; bh[b] = sm; team[sm].push_back(a); team[sm].push_back(b); sm++; }//可能的问题在于，12,34,23：14此时会识别成俩，推荐解法：使用list?存放“友”团体
	}//第二个问题在于，如果两个都有一个“友”帮的帮派成为友帮，数量只-1，事实上应该-2???xxx不是数量问题，因为遇友-1，该情景下相遇时只会有俩
	while (q--)//问题在，12,34，56，78,23,67,45:18，访问1只能看到1234，推荐解法：整体迁移
	{//第三个问题是，如果本来就在一个队里，会死循环吧（可是报的是答案错误不是超时）
		int a, b; cin >> a >> b;
		if (bh[a] == bh[b] && bh[a])
			cout << "In the same gang." << endl;
		else cout << "In different gangs." << endl;
	}
	cout << sm - 1 - sm_ << endl;
}
~~~

确实debug不出来哪有问题了，放这记录一下



## 7-5 哈夫曼编码

给定一段文字，如果我们统计出字母出现的频率，是可以根据哈夫曼算法给出一套编码，使得用此编码压缩原文可以得到最短的编码总长。然而哈夫曼编码并不是唯一的。例如对字符串"aaaxuaxz"，容易得到字母 'a'、'x'、'u'、'z' 的出现频率对应为 4、2、1、1。我们可以设计编码 {'a'=0, 'x'=10, 'u'=110, 'z'=111}，也可以用另一套 {'a'=1, 'x'=01, 'u'=001, 'z'=000}，还可以用 {'a'=0, 'x'=11, 'u'=100, 'z'=101}，三套编码都可以把原文压缩到 14 个字节。但是 {'a'=0, 'x'=01, 'u'=011, 'z'=001} 就不是哈夫曼编码，因为用这套编码压缩得到 00001011001001 后，解码的结果不唯一，"aaaxuaxz" 和 "aazuaxax" 都可以对应解码的结果。本题就请你判断任一套编码是否哈夫曼编码。



## 7-6 先序和中序构造二叉树

本题目要求用先序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其后序序列。

原理是每次找出子树的根节点并分为更小的子树

~~~#include <iostream>
#include<list>
using namespace std;

list<int> q;
void last(int* a, int* b, int n, int cs)
{
    if (n > 0)
    {
        int root = a[0];//根为先序遍历第一位
        int xb = 0;
        for(int i=0;i<n;i++)
            if (b[i] == root)
            {
                xb = i; break;
            }
        q.push_back(root);
        //左边有xb个节点
        last(a + xb + 1, b + xb + 1, n - xb - 1, cs + 1);//右
        last(a + 1, b, xb, cs + 1);//左
    }
}

int main()//原理是每次找出子树的根节点并分为更小的子树
{
    int cs = 0;
    int n;
    cin >> n;
    int a[101], b[101];  //a[n]先序 b[n]中序
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    last(a, b, n, cs);

    while (!q.empty())
    {
        cout << q.back() << " ";
        q.pop_back();
    }
}
~~~

## 7-7 按层遍历二叉树

用先序和中序序列构造一棵二叉树（树中结点个数不超过10个），通过用队记录结点访问次序的方法实现对二叉树进行按层遍历，即按层数由小到大、同层由左到右输出按层遍历序列。

原理跟先序中序求后序一样

~~~#include <iostream>
#include<list>
using namespace std;

list<int> q[101];
void last(int* a, int* b, int n, int cs)
{
    if (n > 0)
    {
        int root = a[0];//根为先序遍历第一位
        int xb = 0;
        for (int i = 0; i < n; i++)
            if (b[i] == root)
            {
                xb = i; break;
            }
        q[cs].push_back(root);
        //左边有xb个节点        

        last(a + xb + 1, b + xb + 1, n - xb - 1, cs + 1);//右
        last(a + 1, b, xb, cs + 1);//左
    }
}

int main()//原理是每次找出子树的根节点并分为更小的子树
{
    int cs = 0;
    int n;
    cin >> n;
    int a[101], b[101];  //a[n]先序 b[n]中序
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    last(a, b, n, cs);
    for (int i = 0; i < n; i++)
    {
        while (!q[i].empty())
        {
            cout << q[i].back() << " ";
            q[i].pop_back();
        }
    }
}
~~~

## 7-8 中序遍历二叉树

按完全二叉树的层次遍历给出一棵二叉树的遍历序列（其中用0表示虚结点），要求输出该二叉树的深度及中序遍历该二叉树得到的序列。

~~~#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int q[1002];
int c = 0;//层数(高度)
bool flag;
void mid(int n, int cs)
{
    if (q[n] == 0) return;
    c = max(c, cs);
    mid(n * 2, cs + 1);
    if (flag == 0)
    {
        cout << q[n];
        flag = 1;
    }
    else
        cout << ' ' << q[n];
    mid(n * 2 + 1, cs + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        flag = 0;
        memset(q, 0, 1002);
        c = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin>>q[i];
        mid(1, 1);
        cout << endl;
        cout << c << endl;
    }
}
~~~

## 7-9 后序和中序构造二叉树

本题目要求用后序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其先序序列。

原理跟先序中序求后序一样

~~~#include <iostream>
using namespace std;

void getpre(int* a, int* b, int n)    //其中数组a为后序,b为中序,n为每次遍历数目
{
    if (n > 0)
    {
        int root = a[n - 1];  //根结点为后序遍历的最后一个
        int xb=0;
        for (int i = 0; i < n; i++)    //在中序遍历中查找根结点
            if (b[i] == root)
            {
                xb = i;
                break;
            }
        cout << root << " " ;
        getpre(a, b, xb);    //对左子树来查找根结点
        getpre(a + xb, b + xb + 1, n - xb - 1);  //对右子树来查找根结点
    }
}

int main()//原理是每次找出子树的根节点并分为更小的子树
{
    int n;
    cin >> n;
    int a[101], b[101];  //a[n]后序 b[n]中序
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];    //输入后序
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];    //输入中序
    }
    getpre(a, b, n);
    return 0;
}