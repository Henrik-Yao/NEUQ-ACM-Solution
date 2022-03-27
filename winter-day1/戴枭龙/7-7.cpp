#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	string s = "", s1 = "";
	while (cin >> c) {
		if (c == '#')//翻译结束
			break;
		else if (c >= 'a' && c <= 'z' ) { //小写字母直接加上去
			s = s + c;
		} else if (c == 'A') {//魔王语言转换
			s = s + "sae";
		} else if (c == 'B') {//魔王语言转换
			s = s + "tsaedsae";
		} else if (c == '(') {//括号内全是小写字母
			while (cin >> c) {
				if (c == ')')//终止条件
					break;
				s1 = s1 + c;//魔王语言特别的地方
			}
			char s2 = s1[0];
			for (int j = s1.length() - 1; j > 0; j--) {
				s = s + s2 + s1[j];
			}
			s = s + s2;
		}
	}
	cout << s;
	return 0;
}