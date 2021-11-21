#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	vector<string>s;
	string t;
	char temp;
	int sum = 0;
	while ((temp=cin.get())!='\n') {
		if (isalpha(temp))t += tolower(temp);
		else {
			if (!t.empty()) { s.push_back(t); t = ""; }
			continue;
		}
	}
	if (!t.empty())s.push_back(t);
	string pat;
	cin >> pat;
	for (auto& c : pat) {
		if(isupper(c))c = tolower(c);
	}
	for (auto c : s) {
		if (search(c.begin(), c.end(), pat.begin(), pat.end()) != c.end())sum++;
	}
	cout << sum;
}