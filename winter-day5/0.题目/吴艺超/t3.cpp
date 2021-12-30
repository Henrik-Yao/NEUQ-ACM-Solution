#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[200010];
int main()
{
	cin>>n;
	for(int i=1;i<=2*n;i++)
		cin>>a[i];
	sort(a+1,a+2*n+1);
	cout<<a[n];
} 
