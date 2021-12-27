#include <bits/stdc++.h>
using namespace std;
vector <char> v;
string s;
int len,pos = 0;
bool type = 0;
int main()
{
	getline(cin,s);
	for (int i = 0;i < s.size(); i++)
	{
		if (s[i] == '[') pos = 0; 
		else if (s[i] == ']') pos = v.size();
		else if (s[i] == '{')
		{
			if (pos > 0) pos--;
		} else if (s[i] == '}')
		{
			if (pos < v.size()) pos++;
		} else if (s[i] == '-') type = 1 - type;
		else if (s[i] == '='){
			if (pos != 0)
			{
				vector <char>:: iterator t = v.begin() + pos - 1;
				v.erase(t);
				pos--;
			}
		} else {
		//	cout << -1 << endl;
			if (type == 0)
			{
				vector <char>:: iterator t = v.begin() + pos;
				v.insert(t,s[i]);
				pos++;
			} else {
				if (pos == v.size())
				{
					v.push_back(s[i]);
					pos++;
				} else {
					v[pos] = s[i];
					pos++;
				}
			}
		}
	}
	for (int i = 0;i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;
	return 0;
}
