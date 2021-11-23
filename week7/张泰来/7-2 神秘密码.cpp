#include <bits/stdc++.h>
using namespace std;
int len1,cnt;
int order[1000005][2],counter[1000005];
string s;
string print(int l,int r)
{
	string copys = "";
	string ans = "";
	l++;
	r--;
	int times = 1;
	if (isdigit(s[l]) && isdigit(s[l + 1]))
	{
		times = (s[l] - '0') * 10 + s[l + 1] - '0';
		l += 2;
	} else {
		times = s[l] - '0';
		l++;
	}
	for (int i = l;i <= r; i++)
	{
		if (s[i] != '[')
		{
			copy += s[i];	
			continue;
		} 
		copys += print(i,counter[i]);
		i = counter[i];
	}
	for (int i = 1;i <= times; i++)
	{
		ans += copys; 
	}
	return ans;
}
int main()
{
	cin >> s;
	len1 = s.size();
	for (int i = 0;i < len1; i++)
	{
		if (s[i] != '[') continue;
		order[++cnt][0] = i; 
	}
	cnt = 0;
	for (int i = len1 - 1;i >= 0; i--)
	{
		if (s[i] != ']') continue;
		order[++cnt][1] = i;
	}
	for (int i = 1;i <= cnt; i++)
	{
		cout << order[i][0] << " " << order[i][1] << endl;
		counter[order[i][0]] = order[i][1];
	}
	for (int i = 0;i <= len1; i++)
	{
		if (s[i] != '[')
		{
			printf("%c",s[i]);
			continue;
		}
		cout << print(i,counter[i]);
		i = counter[i];
	}
}
