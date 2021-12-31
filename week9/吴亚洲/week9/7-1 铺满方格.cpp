#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[55]={0,1,2,4};
int main()
{
	for(int i=4;i<=50;i++)
		a[i]=a[i-3]+a[i-2]+a[i-1];
	int n;
	while(cin>>n)
	cout<<a[n]<<endl;
}
