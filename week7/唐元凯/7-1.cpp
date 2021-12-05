#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	unordered_map<string, string>s;
	vector<string>inq;
	string uni, eng;
	for (size_t i = 0; i < m; i++)
	{
		cin >> eng >> uni;
		s.insert({ uni,eng });
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> uni;
		inq.push_back(uni);
	}
	for (auto c : inq) {
		if (s.find(c) == s.end())cout << "eh" << endl;
		else cout << s[c]<<endl;
	}
}