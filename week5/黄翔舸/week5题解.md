week5题解

7-1

思路：

首先存入输入的关系谱图，标记bool为1，按照题目中的说法，将相近的人进行标记后，检索交叉的谱图遍历输出。注意关系的发生不会变化，数据存储应当是始终的。

代码：

#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

vector<int> vec[100005];
bool vis[100005];
char gender[100005];
bool flag;

void dfs(int x, int num)
{
    if (num >= 4)
    {
        return;
    }
    int u = vec[x].size();
    for (int i = 0; i < u; i++)
    {
        if (!vis[vec[x][i]])
        {
            vis[vec[x][i]] = 1;
            dfs(vec[x][i], num + 1);
        }
        else
        {
            flag = 1;
            return;
        }
    }
}

int main()
{
    int N;
    int geshu;
    cin >> N;
    while (N--)
    {
        int id;
        int father, mother;
        cin >> id;
        cin >> gender[id];
        cin >> father >> mother;
        if (father != -1)
        {
            vec[id].push_back(father);
            gender[father] = 'M';
        }
        if (mother != -1)
        {
            vec[id].push_back(mother);
            gender[mother] = 'F';
        }
    }
    cin >>geshu;
    while (geshu--)
    {
        int x, y;
        cin >> x >> y;
        if (gender[x] == gender[y])
        {
            cout << "Never Mind";
        }
        else
        {
            memset(vis, 0, sizeof(vis));
            flag = 0;
            dfs(x, 0);
            dfs(y, 0);
            if (flag)
            {
                cout << "No";
            }
            else
            {
                cout << "Yes";
            }
        }
        if (geshu != 0)
        {
            cout << endl;
        }
    }

    return 0;

}

7-2

首先这道题是找规律，根据题中假设成立，找素数即可，筛选一共有三种情况，偶数，素数，以及需要进行一次运算的奇数。所以列出，使用欧拉筛中的开方可以缩短运行时间。

#include<iostream>
#include<cmath>

using namespace std;

bool isprime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (!(x & 1)) {
            cout << 2 << endl;
        }
        else {
            if (isprime(x)) {
                cout << 1 << endl;
            }
            else if (isprime(x - 2)) { 
                cout << 2 << endl;
            }
            else {            
                cout << 3 << endl;
            }
        }
    }
    return 0;
}

7-3

遍历，但是本题是有向图，深度优先，做好回溯即可。

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define w 20005
using namespace std;

int read()
{
	int res = 0, x = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')
			x = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res * x;
}

struct bianli
{
	int next, to;
}g[w<< 1];
int n, m, aa, bb, num, last[w], vis[w];

void dfs(int x)
{
	if (vis[x]) return;
	vis[x] = 1;
	int a[w], tot = 0;
	if (x == 1)
	{
		cout << "0"<<" ";
	}
	else
	{
		cout << x - 1<<" ";
	}
	for (int i = last[x]; i; i = g[i].next)
	{
		int v = g[i].to;
		if (!vis[v])
			a[++tot] = v;
	}
	sort(a + 1, a + 1 + tot);
	for (int i = 1; i <= tot; i++)
	{
		dfs(a[i]);
	}
}
void jia(int from, int to);
int main()
{
	n = read(); m = read();
	for (int i = 1; i <= m; i++)
	{
		aa = read(); bb = read();
		aa++; bb++;
		jia(aa, bb);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			dfs(i);
	}
	return 0;
}
void jia(int from, int to)
{
	g[++num].next = last[from];
	g[num].to = to;
	last[from] = num;
}

7-4

列出标记的山，遍历记录排除所有不是大山的情况，输出个数即可。

#include<iostream>

using namespace std;
int sum = 0;
int m, n;
bool shan[2001][2001];
void lian(int i, int j)
{
	int row[4] = { 0,1,0,-1 };
	int col[4] = { 1,0,-1,0 };
	for (int k = 0; k <= 3; k++)
	{
		if (row[k] + i >= 0 && col[k] + j >= 0 && row[k] + i < m && col[k] + j < n && shan[row[k] + i][col[k] + j])
		{
			shan[row[k] + i][col[k] + j] = 0;
			lian(row[k] + i, col[k] + j);
		}
	}
}
void xz(int i, int j)
{
	if (shan[i][j])
	{
		sum++;
		lian(i, j);
	}
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{


		for (int j = 0; j < n; j++)
		{
			cin >> shan[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			xz(i, j);


​			
​			
		}
	}
	cout << sum;
	
	return 0;
}

7-5

一开始没有想到这是一道遍历题，只把当成了很简单的筛选，跳出，然而重复数据的存在，会导致输出不一样的结果，所以还是应当使用遍历，不过，可能多设几个标记来存储重复的数据，再进行排序可能也行吧。

#include<iostream>
using namespace std;
bool bj;
int m[50001], rk, length, jud[50001];
void end(int rk);
int main()
{

	cin >> length;
	for (int i = 0; i < length; i++) cin >> m[i];
	cin >> rk;
	end(rk);
	if (bj) cout << "True";
	else cout << "False";
	return 0;
}
void end(int rk)
{
	jud[rk] = 1;
	if (m[rk] == 0)
	{
		bj = 1;
		return;
	}
	if ((jud[rk + m[rk]] || rk + m[rk] >= length) && (jud[rk - m[rk]] || rk - m[rk] < 0)) return;
	if (rk + m[rk] < length)
		end(rk + m[rk]);
	if (rk - m[rk] >= 0)
		end(rk - m[rk]);

}

