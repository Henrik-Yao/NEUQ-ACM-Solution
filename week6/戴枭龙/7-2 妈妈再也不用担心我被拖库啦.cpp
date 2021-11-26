#include <bits/stdc++.h>
using namespace std;
map<string, string>record;
map<string, vector<int>>hash1;

vector<int>hash2(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
	int x;
	vector<int>number;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			x = s[i] - '0';
		} else {
			x = s[i] - 'a' + 10;
		}
		number.push_back(x);//尾部添加元素。
	}
	vector<int>ans;//将字符串平均划为4块，保证在前的分块不短于在后的分块,长度不超过1。
	int ave = s.size() / 4, cnt = ave * 4, pos = 0;
	for (int k = 0; k < 4; k++) {
		int length = ave;
		if (cnt < s.size()) {
			cnt++;
			length++;
		}
		int n = 0;
		for (int j = pos; j <= length + pos - 1; j++) {
			n += number[j];
		}
		pos += length;
		ans.push_back(n % 36);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		char action;
		string ID, pwd;
		cin >> action >> ID >> pwd;
		if (action == 'R') { //如果是注册操作
			if (record.count(ID)) //注册过
				puts("Repeated!");
			else { //没注册过
				record[ID] = pwd;
				hash1[ID] = hash2(pwd);
				puts("Signed!");
			}
		} else { //如果是登录操作
			if (!record.count(ID)) { //不存在该用户名
				puts("Failed!");
				continue;
			}
			if (record[ID] == pwd) { //密码正确
				puts("Success!");
				continue;
			}
			if (hash1[ID] == hash2(pwd)) //密码错误但哈希值相同
				puts("Attention!");
			else
				puts("Failed!");
		}
	}
	return 0;
}