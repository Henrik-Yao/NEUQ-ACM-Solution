#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
string a1[1009],b, a2[1009];
int kmp[N], bl;
char c;
void Vkmp(string b)
{
	int j = 0, bl = b.size();
	for (int i = 2; i < bl; i++)
	{
		while(j&&b[j+1] != b[i]) j = kmp[j];
		if(b[j+1] == b[i]) j++;
		j = kmp[j];
	}
}
int Kmp(string a)
{
	int j = 0,al = a.size();
	for (int i = 1; i < al; i++)
	{
		while(j&&b[j+1] != a[i]) j = kmp[j];
		if(b[j+1] == a[i]) j++;
		if(j == bl-1)
			return 1;
	}
	return 0;
}
int main()
{
	int t = 1, ans = 0;
	a1[1] = " ";
	while(scanf("%c", &c) != '\n')
		{
			if(c>='a'&&c<='z') c = char(c-'a'+'A');
			if(c < 'A' || c > 'Z')
			{
//				cout << a1[t] << endl;
				if(a1[t] != " ") 
					a1[++t] = " ";
			}
			else a1[t]+=c;
		}
	b = a1[t-1];
	bl = b.size();
//	cout << b;
//	cout << t;
//	for (int i = 1; i < t; i++) cout << a1[i] << endl;
	Vkmp(b);
	for (int i = 1; i < t-1; i++) 
		ans += Kmp(a1[i]);
	cout << ans;
	return 0;
}
