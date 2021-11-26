#include <iostream>
#include<cstring>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
map<string, string>user;

int s1, s2, s3, s4;

string hash1(string code) {
	int len = code.size();
	int remp = len % 4;
	switch (remp) {
	case 0: {
		s1 = s2 = s3 = s4 = len / 4;
		break;
	}
	case 1: {
		s1 = len / 4 + 1;
		s2 = s3 = s4 = len / 4;
		break;
	}
	case 2: {
		s1 = s2 = len / 4 + 1;
		s3 = s4 = len / 4;
		break;
	}
	case 3: {
		s1 = s2 = s3 = len / 4 + 1;
		s4 = len / 4;
		break;
	}
	}



	int sum[5] = { 0,0,0,0,0 };
	for (int i = 0; i < s1; i++) { 

		if (code[i] <= 'Z' && code[i] >= 'A')
			code[i] = code[i] - 'A' + 'a';
		if (code[i] <= 'z' && code[i] >= 'a') {
			int shu = code[i];
			shu = code[i] - 'a' + 10;
			sum[1] += shu;
		}
		if (code[i] <= '9' && code[i] >= '0') {
			int shu = code[i];
			shu = code[i] - '0';
			sum[1] += shu;
		}
	}
	for (int i = s1; i < s1 + s2; i++) { 

		if (code[i] <= 'Z' && code[i] >= 'A')
			code[i] = code[i] + 32;
		if (code[i] <= 'z' && code[i] >= 'a') {
			int shu = code[i];
			shu = code[i] - 87;
			sum[2] += shu;
		}
		if (code[i] <= '9' && code[i] >= '0') {
			int shu = code[i];
			shu = code[i] - 48;
			sum[2] += shu;
		}
	}
	for (int i = s1 + s2; i < s1 + s2 + s3; i++) { 

		if (code[i] <= 'Z' && code[i] >= 'A')
			code[i] = code[i] + 32;
		if (code[i] <= 'z' && code[i] >= 'a') {
			int shu = code[i];
			shu = code[i] - 87;
			sum[3] += shu;
		}
		if (code[i] <= '9' && code[i] >= '0') {
			int shu = code[i];
			shu = code[i] - 48;
			sum[3] += shu;
		}
	}
	for (int i = s1 + s2 + s3; i < s1 + s2 + s3 + s4; i++) { 

		if (code[i] <= 'Z' && code[i] >= 'A')
			code[i] = code[i] + 32;
		if (code[i] <= 'z' && code[i] >= 'a') {
			int shu = code[i];
			shu = code[i] - 87;
			sum[4] += shu;
		}
		if (code[i] <= '9' && code[i] >= '0') {
			int shu = code[i];
			shu = code[i] - 48;
			sum[4] += shu;
		}
	}
	for (int i = 1; i <= 4; i++) {
		sum[i] = sum[i] % 36;
	}
	string zan;
	for (int i = 0; i < 4; i++) {
		char ch;
		if (sum[i + 1] <= 9 && sum[i + 1] >= 0) {
			ch = sum[i + 1] + '0';
			
			zan += ch;
		}
		if (sum[i + 1] <= 36 && sum[i + 1] > 9) {
			ch = sum[i + 1] - 10 + 'a';
			
			zan += ch;
		}
	}
	return zan;
}
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		char ch;
		cin >> ch;
		string str;
		string remp;
		cin >> str;
		cin >> remp;
		if (ch == 'R') {
				
			if (user.count(str))
				cout << "Repeated!";
			else {
				user[str] = remp;
				cout << "Signed!";
				
			}
		}
		if (ch == 'L') {
			
			if (user[str] == remp) {
				cout << "Success!";
			}
			else if (hash1(user[str]) == hash1(remp)) {
				
				cout << "Attention!";
			}
			else {
				cout << "Failed!";
			}
		}
		cout << "\n";
	}

	return 0;
}