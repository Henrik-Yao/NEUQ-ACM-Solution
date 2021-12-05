#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        int n;
        cin>>n;
        int i,j,a[n],dp[n];
        for(i=0;i<n;i++)
        {
            dp[i]=0;
            cin>>a[i];
            if(i==0)
            {
                dp[0]=1;
            }
            else
            {
                for(j=0;j<i;j++)
                {
                    if(a[i]>a[j])
                        dp[i]=max(dp[j],dp[i]);
                }
                dp[i]++;
            }
        }
        cout<<*max_element(dp,dp+n)<<endl;
        if(q!=t-1)
            cout<<endl;
    }
    
}

