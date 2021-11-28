#include <bits/stdc++.h>
using namespace std;
int t, n, a[1010], d[1010];

int main(void)
{
    cin>>t;
    while(t--)
    {
    	int ans=0;
    	cin>>n;
    	for(int i=0; i<n; i++)
    		cin>>a[i], d[i]=1;
    	for(int i=0; i<n; i++)
    	{
    		for(int j=0; j<i; j++)
    			if(a[i]>a[j])
    				d[i]=max(d[i], d[j]+1);
    		ans=max(ans, d[i]);
		}
	cout<<ans<<endl;
	if(t)
		cout<<endl;
	}
    
	return 0;
}