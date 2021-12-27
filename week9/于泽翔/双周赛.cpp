#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, m, a[11111], w=0;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>a[i];
	
	sort(a, a+n);
	for(int i=0; i<n-1; i++)
		a[i]=a[i+1]-a[i]-1;
	sort(a, a+n);
	
    if(n-m)
	for(int i=0; i<n-m; i++)
		w+=a[i];
	cout<<n+w;
	
	return 0;
}