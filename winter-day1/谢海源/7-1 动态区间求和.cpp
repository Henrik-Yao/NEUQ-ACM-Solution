#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
int num[maxn];
int sum[maxn<<2],add[maxn<<2];//四倍空间
void push_up(int rt)//向上更新
{
	sum[rt] = sum[rt <<1] + sum[rt <<1 | 1];
}
void push_down(int rt, int m)//更新子节点
{
	if (add[rt])
	{
		add[rt <<1] += add[rt];
		add[rt <<1|1] += add[rt];
		sum[rt <<1] += (m - (m >>1)) * add[rt];
		sum[rt <<1|1] += (m >>1) * add[rt];
		add[rt] = 0;
	}
}
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
void build(int l, int r, int rt)//建树
{
	add[rt] = 0;
	if (l == r)
	{
		cin >> sum[rt];//赋值
		num[l] = rt;//记录节点位置
		return;
	}
	int mid = (l + r) >>1;
	build(lson);
	build(rson);
	push_up(rt);//向上更新区间和

}

void update(int a,int b,int c,int l,int r,int rt)//区间更新
{
	if (a <= l && b >= r)
	{
		sum[rt] += (r - l + 1) * c;
		add[rt] += c;
		return;
	}
	push_down(rt, r - l + 1);
	int mid = (l + r) >> 1;
	if (a <= mid) update(a, b, c, lson);
	if (b > mid) update(a, b, c, rson);
	push_up(rt);
}

int query(int a, int b, int l, int r, int rt)//区间求和
{
	if (a <= l && b >= r) return sum[rt];
	push_down(rt, r - l + 1);
	int mid = (l + r) >>1;
	int ans = 0;
	if (a <= mid) ans += query(a, b, lson);
	if (b > mid) ans += query(a, b, rson);
	return ans;
}
signed main()
{
	int n, q;
	cin >> n >> q;
	build(1, n, 1);//建树
	while (q--)
	{
		int t,y, z;
		cin >> t >> y >> z;
		if (t == 1)
		{
			update(y,y,z,1,n,1);
		}
		else if(t==2)
		{
			//printf("d\n", query(y, z, 1, n, 1));
			cout<<query(y, z, 1, n, 1)<<endl;
		}
	}
	return 0;
}