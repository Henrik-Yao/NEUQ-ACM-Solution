#include <bits/stdc++.h>
using namespace std;
struct dict {
	string s;
	int times,id;
	friend bool operator <(dict x,dict y)
	{
		if (x.times != y.times) return x.times < y.times;
		else return x.s > y.s;
	}
};
struct question{
	int id,l,r;
	string s;
	vector <dict> ans;
}q[20005];
priority_queue <dict> pq;
map <string,int> maps;
int n,m,k,t,val,l,r;
bool on_queue[100005];
string s[100005];
bool cmp1(question &x,question &y)
{
	bool f1 = 1,f2 = 1;
	if (x.l == -1 || x.r == -1) f1 = 0;
	if (y.l == -1 || y.r == -1) f2 = 0;
	if (f1 == 0 || f2 == 0) return f1 > f2;
	int num1 = x.l / t;
	int num2 = y.l / t;
	return (num1 ^ num2) ? num1 > num2 : ((num1 & 1)?x.r < y.r:x.r > y.r);
}
int find_l(string s1)
{
	int l = 0,r = n + 1;
	while (r - l > 1)
	{
		int mid = l + (r - l) / 2;
		if (s1 < s[mid]) r = mid;
		else l = mid;
	}
	if (r == n + 1) return -1;
	return l;
}
int find_r(string s1)
{
	int l = 0,r = n + 1;
	while (r - l > 1)
	{
		int mid = l + (r - l) / 2;
		if (s[mid].find(s1) == 0 || s[mid] <= s1) l = mid;
		else r = mid;
	}
	
	if (l == 0) return -1;
	return r;
}
bool cmp2(question &x,question &y)
{
	return x.id < y.id;
}
int main()
{
	cin >> n >> m >> k;
	t = sqrt(n);
	for (int i = 1;i <= n; i++)
	{
		cin >> val >> s[i];
		maps[s[i]] = max(maps[s[i]],val);
	}
	sort(s + 1,s + n + 1);
	n = unique(s + 1,s + n + 1) - s - 1;
	for (int i = 1;i <= m; i++)
	{
		cin >> q[i].s;
		q[i].id = i;
		q[i].ans.clear();
		int L = find_l(q[i].s),R = find_r(q[i].s);
		if (L != -1) q[i].l = L + 1;
		else q[i].l = -1;
		if (R != -1) q[i].r = R - 1;
		else q[i].r = -1;
	}
	sort(q + 1,q + m + 1,cmp1);
	for (int i = 1;i <= m; i++)
	{
		int tot = 0;
		if (q[i].l == -1 || q[i].r == -1) break;
		while (r < q[i].r)
		{
			++r;
			if (on_queue[r]) continue;
			on_queue[r] = 1;
			dict A = {s[r],maps[s[r]],r};
			pq.push(A);
		}
		while (l > q[i].l)
		{
			--l;
			if (on_queue[l]) continue;
			on_queue[l] = 1;
			dict A = {s[l],maps[s[l]],l};
			pq.push(A);
		}
		l = q[i].l; r = q[i].r;
		while (!pq.empty())
		{
			dict cur = pq.top();
			pq.pop();
			on_queue[cur.id] = 0;
			if (cur.id >= q[i].l && cur.id <= q[i].r)
			{
				tot++;
				q[i].ans.push_back(cur);
				if (tot == k) break;
			}
		}
		for (int j = 0;j < q[i].ans.size(); j++)
		{
			on_queue[q[i].ans[j].id] = 1;
			pq.push(q[i].ans[j]);
		}
	}
	sort(q + 1,q + m + 1,cmp2);
	for (int i = 1;i <= m; i++)
	{
		if (!q[i].ans.size())
		{
			printf("no suggestion\n");
		} else {
			for (int j = 0;j < q[i].ans.size(); j++)
			{
				cout << q[i].ans[j].s << endl;
			}
		}
		if (i < m) cout << endl;
	}
	return 0;
}
