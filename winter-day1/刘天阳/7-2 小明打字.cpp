#include <bits/stdc++.h>
using namespace std;
string a, ans;
int main()
{
	
	int l = 0, ju = 1;
	getline(cin,a);
	int len = a.size();
	for(int i = 0; i < len; i++)
	{	
		char c = a[i];
		if(c == '[') l = 0;
		else if(c == ']') l = ans.length();
		else if(c == '{') l = max(0, l-1);
		else if(c == '}') l = min(int(ans.length()),l+1);
		else if(c == '=') 
		{
			ans.erase(l = max(0,l-1), 1);
		} 
		else if(c == '-') ju ^= 1;
		else 
		{
			if(ju)	ans.insert(l,1,c);
			else ans[l] = c;
			l++;
		}
		
	}
	cout << ans;
	return 0;
}
