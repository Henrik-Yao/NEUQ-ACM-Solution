#include <bits/stdc++.h>
using namespace std;
multiset<int>s;
int main()
{
	int n,a;
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>a;
		s.insert(a); 
	}
	int pos=(s.size()+1)/2;
	int cnt=0;
	for(auto i=s.begin();i!=s.end();i++)
	{
		cnt++;
		if(cnt==pos)
		{
			cout<<*i;
		}
	}
	return 0;
}
