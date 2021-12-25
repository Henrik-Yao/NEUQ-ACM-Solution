#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	vector<int>train[100];
	cin >> n;
	int temp, diff = 100, sum = 1, pos = 0, sig = 1;
	bool ok = 0;
	//Initialize first rail
	cin >> temp; train[sum].emplace_back(temp); n--;

	while (n--) {
		ok = 0; diff = 100;
		cin >> temp;
		for (size_t i = 1; i <= sum; i++)
		{
			if (train[i].back() > temp) {
				ok = 1;
				if (diff > train[i].back() - temp) {
					pos = i;
					diff = train[i].back() - temp;
				}
			}
		}
		if (ok) {
			train[pos].emplace_back(temp);
			if (temp == 1)sig = pos;
		}
		else train[++sum].emplace_back(temp);
	}
	for (auto &c : train[sig]) {
		cout << c;
		if (&c != &train[sig][train[sig].size()-1])cout << " ";
	}
	cout << endl;
	cout << sum;
}
