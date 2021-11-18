#include<iostream>
#include<cstring>
using namespace std;

int m[50005];
int n;
bool flag = false;
bool vis[50005];

void search(int start) {
	if (start >= n || start < 0)return;
	if (m[start] == 0)flag = true;
	if (vis[start]||flag)return;
	vis[start] = 1;
	search(start + m[start]);
	search(start - m[start]);

}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> m[i];
	}
	int start;
	cin >> start;
	//EOI
	memset(vis, 0, sizeof(vis));
	search(start);
	if (flag)cout << "True"<<endl;
	else cout << "False"<<endl;
}
