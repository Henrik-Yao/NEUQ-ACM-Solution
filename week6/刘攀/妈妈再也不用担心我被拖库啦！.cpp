#include<iostream>
#include<map>
#include<string.h>
using namespace std;
map<string, pair<string, string> > mp;
struct Node {
	string c;
	string zh;
	string mm;
	string hx;
};
Node node[1001];
char gethash(string c) {
	int sum = 0;
	for (int i = 0; i < c.size(); i++) {
		if (c[i] >= 'A' && c[i] <= 'Z') c[i] += 32;
		if (c[i] >= '0' && c[i] <= '9') c[i] -= '0';
		else if (c[i] >= 'a' && c[i] <= 'z') c[i] = c[i] - 'a' + 10;
		sum += c[i];
	}
	sum = sum % 36;
	if (sum >= 0 && sum <= 9) return (sum + '0');
	else return (sum + 'a' - 10);
}
string hashh(string c) {
	int l = c.size();
	int index[5] = { 0 };
	string hx = "0000";
	for (int i = 0; i < l % 4; i++) {
		index[i]++;
	}
	int j = 0;
	for (int i = 0; i < 4; i++) {
		index[i] += l / 4;
		string str1 = c.substr(j, index[i]);
		char h = gethash (str1);
		hx[i] = h;
		j += index[i];
	}
	return hx;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> node[i].c >> node[i].zh >> node[i].mm;
		node[i].hx = hashh(node[i].mm);
		if (node[i].c == "R") {
			if (mp.find(node[i].zh) != mp.end()) {
				cout << "Repeated!" << endl;
			}
			else {
				mp[node[i].zh].first = node[i].mm;
				mp[node[i].zh].second = node[i].hx;
				cout << "Signed!" << endl;
			}
		}
		else if (node[i].c == "L") {
			if (mp.find(node[i].zh) == mp.end()) {
				cout << "Failed!" << endl;
			}
			else {
				if (mp.find(node[i].zh)->second.first == node[i].mm) {
					cout << "Success!" << endl;
				}
				else {
				if (mp.find(node[i].zh)->second.second == node[i].hx) {
					cout << "Attention!" << endl;
				}
				else cout << "Failed!" << endl;
			}
			}
		}
	}
}
