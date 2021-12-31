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
		number.push_back(x);//β�����Ԫ�ء�
	}
	vector<int>ans;//���ַ���ƽ����Ϊ4�飬��֤��ǰ�ķֿ鲻�����ں�ķֿ�,���Ȳ�����1��
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
		if (action == 'R') { //�����ע�����
			if (record.count(ID)) //ע���
				puts("Repeated!");
			else { //ûע���
				record[ID] = pwd;
				hash1[ID] = hash2(pwd);
				puts("Signed!");
			}
		} else { //����ǵ�¼����
			if (!record.count(ID)) { //�����ڸ��û���
				puts("Failed!");
				continue;
			}
			if (record[ID] == pwd) { //������ȷ
				puts("Success!");
				continue;
			}
			if (hash1[ID] == hash2(pwd)) //������󵫹�ϣֵ��ͬ
				puts("Attention!");
			else
				puts("Failed!");
		}
	}
	return 0;
}