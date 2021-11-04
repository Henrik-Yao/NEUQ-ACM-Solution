#include <bits/stdc++.h>
using namespace std;
unsigned long long a[88]={0}, b[88];
int n;
int main(void)
{
	for(int i=1; i<65; i++)
    {
    	a[i]=2*a[i-1]+1;
    	b[i]=a[i];
	}
    
    for(int i=1; i<65; i++)
    	for(int j=0; j<i; j++)
    		b[i]=min(b[i], 2*b[j]+a[i-j]);
    
    while(cin>>n)
    	cout<<b[n]<<endl;
	
	return 0;
}