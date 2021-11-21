#include<bits/stdc++.h>
using namespace std;
bool judge[10000005];
int main()
{
	int n,cnt=0;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(judge[i])
		continue;
		for(int j=i;j<=n;j+=i)
		judge[j]=1;
		cnt++;
	}
	cout<<cnt;
}
