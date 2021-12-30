#include<iostream>
#include<map>
using namespace std;
map<int, int>mp;
int main() {
	int n;
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		mp[x]++;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << ":" << it->second << endl;
	}
}
