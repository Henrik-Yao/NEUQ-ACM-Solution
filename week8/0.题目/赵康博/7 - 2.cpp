#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int f[n];
    for(int i = 0; i < n; i++)
    {
        cin>>f[i];
    }
    int t = 0;
    int count = 0;
    while(1)
    {
        int max1 = f[t] + t;
        int tmp = t;
        for(int i = t + 1; i <= f[t]+t; i++)
        {
            if(f[i]+i>max1)
            {
                max1 = f[i]+i;
                tmp = i;
            }
        }
        t = tmp;
        count++;
        if(f[t]+t>=n)break ;
    }
    cout<<count+1;
    return 0;
}