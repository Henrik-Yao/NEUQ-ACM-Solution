/*#include<iostream>
#include<stack>
using namespace std;

stack <char> kuohao;

int main() {
	string s;
	while (cin >> s) {
        int flag1 = 0,flag2 = 0;
        for (int i = 0; i < s.length(); i++) {
            char temp = s[i];
            if (temp == '(')
                kuohao.push(temp);
            else {
                if (kuohao.empty()) {
                    flag1++;
                }
                else kuohao.pop();
            }
        }
        while (!kuohao.empty()) {
            flag2++;
            kuohao.pop();
        }
        if (flag1 + flag2 == 0) cout << "Match"<<endl;
        else {
            cout << flag1 + flag2 << endl;
            for (int i = 0; i < flag1; i++)cout << '(';
            cout << s;
            for (int i = 0; i < flag2; i++)cout << ')';
            cout << endl;
        }
	}
}*/