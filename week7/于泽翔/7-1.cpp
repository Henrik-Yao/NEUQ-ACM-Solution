#include <bits/stdc++.h>
using namespace std;
map<string, string> M;
int main(void)
{
	int n, m;
	string a, b;
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		M[b]=a;
	}
	for(int i=0; i<m; i++)
	{
		cin>>a;
		if(M.find(a)==M.end())
			puts("eh");
		else
			cout<<M[a]<<endl;
	}
	
	return 0;
}