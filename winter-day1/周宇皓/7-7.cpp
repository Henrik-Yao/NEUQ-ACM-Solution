#include<bits/stdc++.h>
using namespace std;

void func(string a) {
	stack<char> s;
	char e;
	int state = 1;
	int i = 0;
	while (i < a.length() && state) {
		switch (a[i])
		{
		case'(': {
			s.push(a[i]);
			i++;
			break;
		}case'[': {
			s.push(a[i]);
			i++;
			break;
		}case'{': {
			s.push(a[i]);
			i++;
			break;
		}
		case ')': {

			if (!s.empty() && s.top() == '(') {
				s.pop();
				i++;
			}
			else
				state = 0;
			break;
		}case ']': {

			if (!s.empty() && s.top() == '[') {
				s.pop();
				i++;
			}
			else
				state = 0;
			break;
		}case '}': {

			if (!s.empty() && s.top() == '{') {
				s.pop();
				i++;
			}
			else
				state = 0;
			break;
		}
		default:
                i++;
			break;
		}
	}

	if (state&&s.empty())
		cout << "yes";
	else
		cout << "no";
}
int main() {
	string a;
	cin >> a;
	func(a);
}
	
