#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
typedef unsigned long long ll;
ll a[65],b[65];
using namespace std;
int main()
{
    ll n,i,j;
    
    a[0]=0;
    b[0]=0;
    b[1]=1;
    b[2]=3;
    for(i=1;i<=64;i++)
    {
        a[i]=2*(a[i-1]+1)-1;
    }
        
    for(i=3;i<=64;i++)
        for(j=1;j<=i;j++)
        {
		
        if(b[i]!=0)
        {
        b[i]=min(b[i],2*b[j]+a[i-j]);
    	}
        else
        b[i]=2*b[j]+a[i-j];
    	}
    while(cin>>n)
    {
    cout<<b[n]<<endl;
    }   
}
