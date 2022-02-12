#include <bits/stdc++.h>
using namespace std;
stack<char>q;
int ju(char a, char b)
{
	if(a == '[' && b == ']') return 1;
	else if(a == '{' && b == '}') return 1;
	else if(a == '(' && b == ')') return 1;
	return 0;
}
int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '{' || s[i] == '(' || s[i] == '[') q.push(s[i]);
		else 
		{
			if(s[i] == ')' || s[i] == '}' || s[i] == ']') 
			{
//				cout << q.top() << " " << s[i] << endl;
				if(!q.empty() && ju(q.top(),s[i]))
				{
					q.pop();continue;
				} 
				else 
				{
					cout << "no";
					return 0;
				}
			}
		}
	}
	if(!q.empty()) cout << "no";
	else cout << "yes";
	return 0;
}
