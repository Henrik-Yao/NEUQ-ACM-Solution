#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
int a[100005];
int b[55];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=0;i<=50;i++)
	{
		if(b[i])cout<<i<<":"<<b[i]<<endl;
	}
	return 0;
}

