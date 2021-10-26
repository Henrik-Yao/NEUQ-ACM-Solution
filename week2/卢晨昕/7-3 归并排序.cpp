#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
