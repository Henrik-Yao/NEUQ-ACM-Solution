#include<bits/stdc++.h>
using namespace std;
int main()
{
	int result[5001];
	result[1]=1;
	result[2]=2;
	for(int i=3;i<=5000;i++)
	result[i]=result[i-1]+result[i-2];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		cout<<result[k-1]<<endl;
	}
}
