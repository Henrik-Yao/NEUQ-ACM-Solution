#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main() {
	int n;
	cin >> n;
	multiset<int>a;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		a.insert(t);
	}
	int cur = -999;
	for (auto c : a) {
		if (cur == c)continue;
		cur = c;
		cout << c << ":" << a.count(c) << endl;
	}
}