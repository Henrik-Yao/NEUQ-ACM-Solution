#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

struct bag
{
	int value = 0, weight = 0;
};

int main() {
	int f[1505];
	int n, c, ans = 0;
	while (cin >> n >> c) {
		ans = 0;
		memset(f, 0, sizeof(f));
		vector<bag>data(n + 5);
		for (size_t i = 0; i < n; i++)
		{
			cin >> data[i].weight;
		}
		for (size_t i = 0; i < n; i++)
		{
			cin >> data[i].value;
		}
		for (size_t i = 0; i < n; i++)
		{
			int W = data[i].weight, V = data[i].value;
			for (int j = c; j >= 0; j--)
			{
				if (j >= W) f[j] = max(f[j], f[j - W] + V);
			}
		}
		for (size_t i = 0; i <= c; i++)
		{
			ans = max(ans, f[i]);
		}
		cout << ans << endl;
	}
}