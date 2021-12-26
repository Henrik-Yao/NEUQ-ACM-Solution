#include <bits/stdc++.h>
using namespace std;
int head,tail;
string s;
bool check()
{
	head = 0;
	tail = s.size() - 1;
	while (head < tail)
	{
		if (s[head] != s[tail]) return false;
		head++;
		tail--;
	}
	return true;
}
int main()
{
	cin >> s;
	if (check())
	{
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
	return 0;
}
