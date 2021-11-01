#include <bits/stdc++.h>
using namespace std;
long long hnt(int n)
{
	if(n==0)
	return 0;
	if(n==1)
	return 2;
	else return hnt(n-1)*3+2;
}
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<hnt(n)<<endl;
	}
	return 0;
}
