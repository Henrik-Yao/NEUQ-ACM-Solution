#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	for (size_t i = 0, length = s.length(); i < length; i++)
	{
		if (s[i] == 'B')cout << "tsaedsae";
		else if (s[i] == 'A')cout << "sae";
		else if (s[i] == '(') {
			++i; char sig = s[i];
			++i; string temp;
			while (s[i] != ')') {
				temp += s[i];
				++i;
			}
			reverse(temp.begin(), temp.end());
			for (auto c : temp) {
				cout << sig << c;
			}
			cout << sig;
		}
	}
}
