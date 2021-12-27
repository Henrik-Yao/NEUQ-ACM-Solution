#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int l = 0, r = 0;
  //遍历数组，并翻译
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(')//将括号出现的位置打上标记，后面翻译用
      l = i;
    if (s[i] == ')')
      r = i;
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A')
      cout << "sae";
    else if (s[i] == 'B')
      cout << "tsaedsae";
    else if (s[i] == '(') {
      cout << s[i + 1];
      for (int j = r - 1; j >= l + 2; --j)//代码的核心，用一个循环来输出括号内的翻译结果
      {
        cout << s[j];
        cout << s[i + 1];
      }
      i = r;
    } else if (s[i] == '#')
      return 0;
  }
  return 0;
}