#include<iostream>
using namespace std;
int n;
const int maxn = 1e6 + 5;
struct Node {
	int fid=-1, mid=-1;
	int sex;
}fml[maxn];
int flag = 0;
int dfs(Node a, Node b, int s) {
	if ((a.fid == -1 && b.fid == -1) || (a.mid == -1 && b.mid == -1))return 0;
	if (s >= 4)return 0;
	if (a.fid == b.fid || a.mid == b.mid) {
		return 1;
	}
	if (a.fid != -1 && b.fid != -1)
		flag += dfs(fml[a.fid], fml[b.fid], s + 1);
	if (a.mid != -1 && b.fid != -1)
		flag += dfs(fml[a.mid], fml[b.fid], s + 1);
	if (a.fid != -1 && b.mid != -1)
		flag += dfs(fml[a.fid], fml[b.mid], s + 1);
	if (a.mid != -1 && b.mid != -1)
		flag += dfs(fml[a.mid], fml[b.mid], s + 1);
	return flag;
}
int main() {
	cin >> n;
	char c;
	int me, f, m;
	for (int i = 0; i < n; i++) {
		cin >> me >> c >> f >> m;
		fml[me].sex = c == 'M' ? 1 : 0;
		fml[me].fid = f;
		fml[f].sex = 1;
		fml[me].mid = m;
		fml[m].sex = 0;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (fml[a].sex == fml[b].sex) {
			cout << "Never Mind" << endl;
			continue;
		}
		if (dfs(fml[a], fml[b], 0))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
		flag = 0;
	}
	return 0;
}

