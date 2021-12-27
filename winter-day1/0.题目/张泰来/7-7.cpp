#include <bits/stdc++.h>
using namespace std;
stack <int> s;
string s1;
int match[1000005];
void deal(int l,int r)
{
	char x = s1[l];
	for (int i = r;i > l; i--)
	{
		cout << x << s1[i];
	}
	cout << x;
	return;
}
int main()
{
	cin >> s1;
	for (int i = 0;i < s1.size(); i++)
	{
		if (s1[i] == '(') s.push(i);
		else if (s1[i] == ')')
		{
			int cur = s.top();
			s.pop();
			match[cur] = i;
		}
	}
	
	for (int i = 0;i < s1.size(); i++)
	{
		if (s1[i] == 'A') cout << "sae";
		else if (s1[i] == 'B') cout << "tsaedsae";
		else if (s1[i] == '(')
		{
			deal(i + 1,match[i] - 1);
			i = match[i];
		}
	}
}
