#include <bits/stdc++.h>
using namespace std;
stack <char> s;
char s1[1000005];
int len;
bool check()
{
	for (int i = 0;i < len; i++)
	{
		if (s1[i] == '(' || s1[i] == '[' || s1[i] == '{') s.push(s1[i]);
		else if (s1[i] == ')')
		{
			if (s.empty() || s.top() != '(') return false;
			s.pop();
		} else if (s1[i] == ']')
		{
			if (s.empty() || s.top() != '[') return false;
			s.pop();
		} else if (s1[i] == '}')
		{
			if (s.empty() || s.top() != '{') return false;
			s.pop();
		}
	}
	if (!s.empty()) return false;
	return true;
}
int main()
{
	scanf("%s",s1);
	len = strlen(s1);
	if (check())
	{
		printf("yes\n");
	} else {
		printf("no\n");
	}
	return 0;
}
