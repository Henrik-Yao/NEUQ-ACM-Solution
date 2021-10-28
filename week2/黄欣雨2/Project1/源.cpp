#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n;
string a, b, c;
void dfs(int m, string x, string y, string z) {
	if (m == 1) {
		cout << x << "->" << z << endl;
		return;
	}
	dfs(m - 1, x, z, y);
	cout << x << "->" << z << endl;
	dfs(m - 1, y, x, z);
}
int main() {
	cin >> n;
	cin >> a >> b >> c;
	dfs(n, a, b, c);
}