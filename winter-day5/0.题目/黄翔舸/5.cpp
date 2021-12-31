#include<bits/stdc++.h>
#define inf 110000
using namespace std;
map<string, int> mp;
int p[inf], cnt[inf], dx[inf], dy[inf], sex[inf];
string ming[inf], xing[inf];
bool judge(int x, int y)
{
	memset(cnt, 0, sizeof(cnt));
	memset(dx, 0, sizeof(dx));
	memset(dy, 0, sizeof(dy));
	cnt[x] = 1, cnt[y] = 1;
	while (p[x] != -1) {
		cnt[p[x]]++;
		dx[p[x]] = dx[x] + 1;
		if (p[x] == y) return false;
		x = p[x];
	}
	while (p[y] != -1) {
		cnt[p[y]]++;
		dy[p[y]] = dy[y] + 1;
		if (cnt[p[y]] > 1) {
			if (dy[p[y]] >= 4 && dx[p[y]] >= 4) return true;
			else return false;
		}
		y = p[y];
	}
	return true;
}

int main() {
	int n, m;
	cin >> n;
	getchar();
	for (int i = 1; i <= n; i++) {
		cin >> ming[i] >> xing[i];
		mp[ming[i]] = i;
		int t = xing[i].size() - 1;
		if (xing[i][t] == 'm' || xing[i][t] == 'n') sex[i] = 1;
		else sex[i] = -1;


		string s = "";
		if (xing[i][t] == 'n') {
			for (int j = 0; j < t - 3; j++) s += xing[i][j];
		}
		else if (xing[i][t] == 'r') {
			for (int j = 0; j < t - 6; j++) s += xing[i][j];
		}
		xing[i] = s;
	}
	memset(p, -1, sizeof(p));
	for (int i = 1; i <= n; i++) {
		if (mp[xing[i]] > 0) p[i] = mp[xing[i]];
	}
	cin >> m;
	string s1, s2, s3, s4;
	while (m--) {
		cin >> s1 >> s2 >> s3 >> s4;
		int x = mp[s1], y = mp[s3];
		if (!sex[x] || !sex[y]) cout << "NA" << endl;
		else if (sex[x] == sex[y])cout << "Whatever" << endl;
		else {
			if (judge(x, y)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
