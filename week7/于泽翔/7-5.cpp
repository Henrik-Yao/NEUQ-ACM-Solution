#include <bits/stdc++.h>
using namespace std;
int n, c, w[1555]={0}, v[1555]={0}, d[1555]={0};

int main(void)
{
    while(cin>>n>>c)
    {
    	for(int i=1; i<=n; i++)
    		cin>>w[i];
    	for(int i=1; i<=n; i++)
    		cin>>v[i];
    	
    	for(int i=1; i<=n; i++)
    		for(int j=c; j>=w[i]; j--)
   				d[j]=max(d[j], d[j-w[i]]+v[i]);
    	cout<<d[c]<<endl;
	}
    
	return 0;
}