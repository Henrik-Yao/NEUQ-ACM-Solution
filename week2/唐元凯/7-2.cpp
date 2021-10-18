#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

int road[10005][2];

int main() {
	ios::sync_with_stdio(false);
	int n, m, c1, c2;
	cin >> n >> m;
	for (size_t i = 1; i <= m; i++)
	{
		cin >> c1 >> c2;
		road[i][0] = c1;
		road[i][1] = c2;
	}
	int x = 0; cin >> x;
	for (size_t i = 0; i < x; i++)
	{
		int xx, temp, sum = 0; cin >> xx;
		set<int>num;
		for (size_t k = 0; k < xx; k++)
		{
			cin >> temp;
			num.insert(temp);
		}
		for (size_t j = 1; j <= m; j++)
		{
			if (num.count(road[j][0]) || num.count(road[j][1]))++sum;
		}
		if (sum == m)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}