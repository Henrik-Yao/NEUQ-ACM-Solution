#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	string s = "", s1 = "";
	while (cin >> c) {
		if (c == '#')//�������
			break;
		else if (c >= 'a' && c <= 'z' ) { //Сд��ĸֱ�Ӽ���ȥ
			s = s + c;
		} else if (c == 'A') {//ħ������ת��
			s = s + "sae";
		} else if (c == 'B') {//ħ������ת��
			s = s + "tsaedsae";
		} else if (c == '(') {//������ȫ��Сд��ĸ
			while (cin >> c) {
				if (c == ')')//��ֹ����
					break;
				s1 = s1 + c;//ħ�������ر�ĵط�
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