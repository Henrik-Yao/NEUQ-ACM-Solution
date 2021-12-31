#include<bits/stdc++.h>
using namespace std;

map<string, string>a;
int H(string b)
{
	int bl = b.size(), s1, s2, s3, s4, l1 = 0, l2 = 0, l3 = 0, l4 = 0, ans = 0;
	s1 = s2 = s3 = s4 = (bl/4);
	int k = bl%4;
	
	if(k-->0) s1++;
	if(k-->0) s2++;
	if(k-->0) s3++;
	for (int i = 0; i < s1; i++)
	{
		if(b[i] <= '9' && b[i] >= '0') l1 += (b[i]-'0');
		if(b[i] <= 'z' && b[i] >= 'a')  l1 += (b[i]-'a'+10);
		if(b[i] <= 'Z' && b[i] >= 'A')  l1 += (b[i]-'A'+10);
	}
	l1 %= 36;
	ans += l1;
	ans *= 36;
	for (int i = s1; i < s1+s2; i++)
	{
		if(b[i] <= '9' && b[i] >= '0') l2 += (b[i]-'0');
		if(b[i] <= 'z' && b[i] >= 'a')  l2 += (b[i]-'a'+10);
		if(b[i] <= 'Z' && b[i] >= 'A')  l2 += (b[i]-'A'+10);
	}
	cout << endl;
	l2 %= 36;
	ans += l2;
	ans *= 36;
	for (int i = s1+s2; i < s1+s3+s2; i++)
	{
		if(b[i] <= '9' && b[i] >= '0') l3 += (b[i]-'0');
		if(b[i] <= 'z' && b[i] >= 'a')  l3 += (b[i]-'a'+10);
		if(b[i] <= 'Z' && b[i] >= 'A')  l3 += (b[i]-'A'+10);
	}
	l3 %= 36;
	ans += l3;
	ans *= 36;
	for (int i = s1+s2+s3; i < s1+s2+s3+s4; i++)
	{
		if(b[i] <= '9' && b[i] >= '0') l4 += (b[i]-'0');
		if(b[i] <= 'z' && b[i] >= 'a')  l4 += (b[i]-'a'+10);
		if(b[i] <= 'Z' && b[i] >= 'A')  l4 += (b[i]-'A'+10);
	}
	l4 %= 36;
	ans += l4;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		char c;
		string nam, pos;
		cin >> c >> nam >> pos;
		if(c == 'R')
		{
			if(!a.count(nam))
			{
				
				a[nam] = pos;
				cout << "Signed£¡" << endl;
			}
			else cout << "Repeated£¡"  << endl;
		}
		else 
		{
			if(pos == a[nam]) cout << "Success£¡" << endl;
			else 
			{
				if(H(pos) == H(a[nam])) cout << "Attention!" << endl;
				else cout << "Failed!" << endl;
				
			}
		}
	}
	
	return 0;
}
