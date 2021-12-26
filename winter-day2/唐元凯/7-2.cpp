#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<set>
#include<sstream>
using namespace std;

const int maxv = 122 + 3;
char post_order[maxv], in_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_list(char *a) {
	string line;
	if (!getline(cin, line))return false;
	stringstream ss(line);
	n = 0;
	char x;
	while (ss >> x)a[n++] = x;
	return n > 0;
}

bool islegal(char *post, char *in) {
	if (strcmp(post, in) == 0)return true;
	int lenp = strlen(post), leni = strlen(in);
	if (lenp != leni)return false;

	char post_ch = post[lenp - 1];
	int in_ch_pos = 0;
	for (int i = lenp - 1; i >= 0; i--) {
		if (in[i] == post_ch) {
			in_ch_pos = i;
			break;
		}
	}
	set<char>to_ch, from_ch;
	char next_p[maxv]{}, next_i[maxv]{};
	for (int i = 0; i < in_ch_pos; i++) {
		to_ch.insert(post[i]);
		next_p[i] = post[i];
		next_i[i] = in[i];
	}
	for (int i = 0; i < in_ch_pos; i++)
		if (to_ch.insert(in[i]).second) return false;
	for (int i = in_ch_pos; i < lenp; i++)from_ch.insert(post[i]);
	for (int i = in_ch_pos; i < lenp; i++)
		if (from_ch.insert(in[i]).second) return false;

	return islegal(next_p, next_i);
}

char build(int L1, int R1, int L2, int R2) {
	if (L1 > R1)return 0;
	char root = post_order[R2];
	int p = L1;
	while (in_order[p] != root)p++;
	int cnt = p - L1;
	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
	return root;
}

int height = 0,bestans=0;
string ans = "";
void dfs(char root) {
	ans += root;
	if (lch[root]) {
		height++;
		if (height > bestans)bestans = height;
		dfs(lch[root]);
	}
	if (rch[root]) {
		height++;
		if (height > bestans)bestans = height;
		dfs(rch[root]);
	}
	height--;
}

int main() {
	while (read_list(post_order)) {
		read_list(in_order);
		if (islegal(post_order, in_order)) {
			build(0, n - 1, 0, n - 1);
			height = 0; bestans = 0; ans = "";
			dfs(post_order[n - 1]);
			cout << bestans << '\n' << ans << endl;
		}
		else cout << "INVALID" << endl;

		memset(post_order, '\0', sizeof(post_order));
		memset(in_order, '\0', sizeof(in_order));
	}
}
