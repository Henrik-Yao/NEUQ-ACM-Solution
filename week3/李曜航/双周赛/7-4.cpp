#include <bits/stdc++.h>
using namespace std;
int main()  
{
    long long dp[65],_min;
    int i,j,n;
    dp[1]=1;
    dp[2]=3;
    for(i=3;i<65;i++)
    {
        _min=0x7FFFFFFFFFFFFFFF;
        for(j=1;j<i;j++)
            if(2*dp[j]+pow(2.0,i-j)-1<_min)
                _min=2*dp[j]+pow(2.0,i-j)-1;
        dp[i]=_min;
    }
    while(cin>>n)
    {
        cout<<dp[n]<<endl;
    }
}


