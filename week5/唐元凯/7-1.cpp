#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct info
{
	char sex;
	int dad=-1;
	int mom=-1;
};

bool vis[100005];
info id[100005];
bool flag;

void dfs(int per, int gen) {
	if (vis[per]) { flag = 0; return; }
	vis[per] = 1;
	if (gen == 5)return;
	if (id[per].dad != -1)dfs(id[per].dad, gen++);
	if (id[per].mom != -1)dfs(id[per].mom, gen++);
}

int main() {
	//Input area
	int n;
	cin >> n;
	int temp;
	for (size_t i = 1; i <= n; i++)
	{
		cin >> temp;
		cin >> id[temp].sex >> id[temp].dad >> id[temp].mom;
		if (id[temp].dad != -1)id[id[temp].dad].sex = 'M';
		if (id[temp].mom != -1)id[id[temp].mom].sex = 'F';
	}
	//EOI
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int male, female;
		cin >> male >> female;
		flag = 1;
		if (id[male].sex == id[female].sex) { cout << "Never Mind" << endl; continue; }
		memset(vis, 0, sizeof(vis));
		dfs(male, 1);
		dfs(female, 1);
		if (flag)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}