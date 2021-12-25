#include <bits/stdc++.h>
using namespace std;
int n, a[1000010];
int main(void)
{
    cin>>n;
    for(int i=0; i<n; i++)
    	cin>>a[i];
    
    int cur=0, nex=a[0], ans=0;
    for(int i=1; i<n; i++)
    {
    	if(i>cur)
    		ans++, cur=nex;
    	nex=i+a[i]>nex?i+a[i]:nex;
	}
    cout<<ans;
    
	return 0;
}