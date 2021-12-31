#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

#define WA AC
#define RE AC
#define CE AC
#define TLE AC
#define MLE AC

using namespace std;

inline int read ()
{
    int f = 1, x = 0;
    char ch;
    do {ch = getchar (); if (ch== '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar ();} while (ch >= '0' && ch <= '9');
    return f * x;
}

const int N = 5 * (1e5 + 7);
typedef long long ll;

ll n;
ll a[N];
ll xv[N];
ll tree[N];
ll ans;

inline bool cmp (int a, int b)//这里的cmp我们需要判重，然后按照原本的顺序排列，要不sort会出玄学乱排 
{
	return xv[a] == xv[b] ? a > b : xv[a] > xv[b];
}

inline int lb (int x)//lowbit 
{
	return x & -x;
}

inline void go_and_do_it (int x)//单点修改 ，每次加1 
{
	for (int i = x; i <= n; i += lb (i))
	tree[i] ++;
}

inline int find (int x)//查询 
{
	int sum = 0;
	for (int i = x; i > 0; i -= lb (i))
	sum += tree[i];
	return sum;
}

int main ()
{
	n = read ();
	for (int i = 1; i <= n; i ++)
	{
		xv[i] = read ();
		a[i] = i;//对其进行初始化先化成自己在进行排序 
	}
	sort (a + 1 , a + 1 + n, cmp);//对其进行排序 
	for (int i = 1 ; i <= n; i ++)
	{
		go_and_do_it (a[i]);//把数插到树状数组里面 
		ans += find (a[i] - 1);// 每次查询把前缀和加到ans里面 
	}
	printf ("%lld", ans);
    return 0;
}