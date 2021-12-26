#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

struct node {
	string name;
	int st, len;
} a[maxn];
vector <node> v0[105], v[105];
map <string, int> mp;
bool vis[maxn];
double tot;
int N, M, gp[maxn], now, p[maxn];

inline bool cmp(node a, node b) {
	return a.st < b.st || a.st == b.st && mp[a.name] < mp[b.name];
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int S;
		string s;
		cin >> S;
		for (int j = 1; j <= S; ++j) {
			cin >> s;
			v0[i].push_back({ s, 0, 0 });
		}
	}
	for (int i = 1; i <= N; ++i) {
		cin >> a[i].name >> a[i].st >> a[i].len;
		if (a[i].len > 60) a[i].len = 60;
		mp[a[i].name] = i;
		gp[i] = -1;
	}
	for (int i = 1; i <= M; ++i) {
		for (auto j : v0[i]) {
			int id = mp[j.name];
			if (id == 0) continue;
			gp[id] = i;
			v[i].push_back({ a[id].name,a[id].st,a[id].len });
		}
		sort(v[i].begin(), v[i].end(), cmp);
	}
	for (int i = 1; i <= N; ++i) {
		if (vis[i]) continue;
		if (now < a[i].st) now = a[i].st;
		tot += now - a[i].st;
		cout << a[i].name << endl;
		//printf("\t%d\n", now - a[i].st);
		if (gp[i] == -1) { now += a[i].len; continue; }
		++p[gp[i]];
		int add = a[i].len;
		node tp;
		for (int j = p[gp[i]]; j < v[gp[i]].size(); ++j) {
			tp = v[gp[i]][j];
			if (tp.st <= now + add) {
				cout << tp.name << endl;
				//printf("\t%d\n", now + add - tp.st);
				vis[mp[tp.name]] = 1;
				tot += now + add - tp.st;
				add += tp.len;
			}
			else {
				p[gp[i]] = j;
				break;
			}
		}
		now += add;
	}
	printf("%.1lf\n", tot / N);
	return 0;
}
