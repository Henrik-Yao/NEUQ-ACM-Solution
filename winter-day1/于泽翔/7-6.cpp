#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	string a;
	cin>>a;
	int l=a.size()-1, h=a.size()/2;
	
	for(int i=0; i<h; i++)
		if(a[i]!=a[l-i])
		{
			cout<<"no";
			return 0;
		}
	cout<<"yes";
	
	return 0;
}