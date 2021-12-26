#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
struct P {
	string name;
	int sj;
	int pt;
	int pos;
}p[N];
int m, n;
map<string, int> g;
string name;
queue<P> q;
int main() {
	cin >> n >> m;
	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> name;
			g[name] = i;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i].name >> p[i].sj >> p[i].pt;
		if (p[i].pt > 60)
			p[i].pt = 60;
		p[i].pos = i;
		q.push(p[i]);
	}
	int last = 0;
	int ans = 0;
	bool flag[N];
	memset(flag, false, sizeof(flag));
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		if (!flag[temp.pos]) {
			flag[temp.pos] = true;
			if (temp.sj <= last) {
				ans += last - temp.sj;
				last += temp.pt;
			}
			else
				last = temp.sj + temp.pt;
			cout << temp.name << endl;
			for (int i = temp.pos + 1; i < n; i++) {
				if (p[i].sj > last)
					break;
				if (temp.name != p[i].name && !flag[i] && g.count(temp.name) && g.count(p[i].name) && g[temp.name] == g[p[i].name]) {
					flag[i] = true;
					cout << p[i].name << endl;
					ans += (last - p[i].sj);
					last += p[i].pt;
				}
			}
		}
	}
	printf("%.1f", (ans * 1.0) / n);
}
