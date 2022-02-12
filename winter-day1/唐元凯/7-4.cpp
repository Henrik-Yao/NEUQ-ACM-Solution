#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int>num; int temp;
	while (cin >> temp) {
		num.emplace_back(temp);
	}
	sort(num.begin(), num.end());
	for (auto &c : num) {
		cout << c;
		if (&c != &num[num.size() - 1])cout << "->";
	}
	cout << endl;
	bool flag = 1;
	for (int i = 0, length = num.size(); i < length; i++)
	{
		if (flag && num[i] % 2) { cout << num[i]; flag = 0; }
		else if (num[i] % 2)cout << "->" << num[i];
	}
	cout << endl;
	flag = 1;
	for (int i = 0, length = num.size(); i < length; i++)
	{
		if (flag && (num[i] % 2 == 0)) { cout << num[i]; flag = 0; }
		else if (num[i] % 2 == 0)cout << "->" << num[i];
	}
}