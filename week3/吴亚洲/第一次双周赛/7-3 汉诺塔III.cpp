#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	long long a[36];
	a[0]=1;
	for(long long i=1;i<=35;i++)
	a[i]=3*a[i-1];
	while(cin>>n)
	{
		cout<<a[n]-1<<endl;
	}
}
