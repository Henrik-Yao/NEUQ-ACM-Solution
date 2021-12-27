#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, ans;
	getline(cin, s);
	int pos = 0; bool ins = 1;
	for (auto c : s) {
		switch (c)
		{
		case '[':
			pos = 0;
			break;
		case ']':
			pos = ans.length();
			break;
		case '{':
			if (pos > 0)--pos;
			break;
		case '}':
			if (pos < ans.length())++pos;
			break;
		case '-':
			ins = !ins;
			break;
		case '=':
			ans.erase(pos - 1, 1);
			--pos;
			break;
		default:
			if (ins) {
				ans.insert(pos, 1, c);
				++pos;
			}
			else {
				if (ans[pos])ans.erase(pos, 1);
				ans.insert(pos, 1, c);
				++pos;
			}
			break;
		}
	}
	cout << ans;
}